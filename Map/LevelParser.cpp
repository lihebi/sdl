#include "LevelParser.h"
#include "../TextureManager.h"
#include "../Game.h"
#include <zlib.h>
#include "../base64.h"
#include <iostream>
#include "ObjectLayer.h"
#include "../Object/GameObjectFactory.h"

Level* LevelParser::parseLevel(const char *levelFile) {
  std::cout<<"in levelparser"<<std::endl;
  TiXmlDocument levelDocument;
  levelDocument.LoadFile(levelFile);

  Level *pLevel = new Level();

  TiXmlElement *pRoot = levelDocument.RootElement();

  pRoot->Attribute("tilewidth", &m_tileSize);
  pRoot->Attribute("width", &m_width);
  pRoot->Attribute("height", &m_height);

  // parse tileset
  for (TiXmlElement *e=pRoot->FirstChildElement();
  e!=NULL;
  e=e->NextSiblingElement()) {
    if (e->Value() == std::string("tileset")) {
      parseTilesets(e, pLevel->getTilesets());
    }
  }

  // parse both tile layer and object layer
  for (TiXmlElement *e = pRoot->FirstChildElement();
  e!=NULL;
  e=e->NextSiblingElement()) {
    if (e->Value() == std::string("layer") ||
    e->Value() == std::string("objectgroup")) {
      if (e->FirstChildElement()->Value() == std::string("object")) {
        parseObjectLayer(e, pLevel->getLayers());
      } else if (e->FirstChildElement()->Value() == std::string("data")) {
        parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets());
      }
    }
  }

  // parse textures for objects defined in map property
  for (TiXmlElement *e = pRoot->FirstChildElement();
  e!=NULL;
  e=e->NextSiblingElement()) {
    if (e->Value() == std::string("property")) {
      parseTextures(e);
    }
  }

  return pLevel;
}

void LevelParser::parseTilesets(TiXmlElement *pTilesetRoot,
std::vector<Tileset> *pTilesets) {
  TheTextureManager::Instance()->load(
  pTilesetRoot->FirstChildElement()->Attribute("source"),
  pTilesetRoot->Attribute("name"),
  TheGame::Instance()->getRenderer());

  Tileset tileset;
  pTilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
  pTilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
  pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
  pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
  pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
  pTilesetRoot->Attribute("spacing", &tileset.spacing);
  pTilesetRoot->Attribute("margin", &tileset.margin);
  tileset.name = pTilesetRoot->Attribute("name");

  tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);

  pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(TiXmlElement *pTileElement,
std::vector<Layer*> *pLayers,
const std::vector<Tileset> *pTilesets) {
  TileLayer *pTileLayer = new TileLayer(m_tileSize, *pTilesets);

  std::vector<std::vector<int> > data;

  std::string decodedIDs;
  TiXmlElement *pDataNode;

  // actually only one
  for (TiXmlElement *e = pTileElement->FirstChildElement();
  e!=NULL;
  e = e->NextSiblingElement()) {
    if (e->Value() == std::string("data")) {
      pDataNode = e;
    }
  }

  // actually only one element, the text. <data>jsdflai</data>
  for (TiXmlNode *e = pDataNode->FirstChild();
  e!=NULL;
  e = e->NextSibling()) {
    TiXmlText *text = e->ToText();
    std::string t = text->Value();
    decodedIDs = base64_decode(t);
  }

  // uncompress zlib compression
  uLongf numGids = m_width * m_height * sizeof(int);
  std::vector<unsigned> gids(numGids);
  uncompress((Bytef*)&gids[0], &numGids,
  (const Bytef*)decodedIDs.c_str(), decodedIDs.size());

  std::vector<int> LayerRow(m_width);

  // just allocate memory
  for (int j=0;j<m_height;j++) {
    data.push_back(LayerRow);
  }

  for (int rows=0;rows<m_height;rows++) {
    for (int cols=0;cols<m_width;cols++) {
      data[rows][cols] = gids[rows * m_width + cols];
    }
  }

  pTileLayer->setTileIDs(data);

  pLayers->push_back(pTileLayer);
}

void LevelParser::parseTextures(TiXmlElement *pTextureRoot) {
  TheTextureManager::Instance()->load(pTextureRoot->Attribute("value"),
  pTextureRoot->Attribute("name"), TheGame::Instance()->getRenderer());
}

void LevelParser::parseObjectLayer(TiXmlElement *pObjectElement,
std::vector<Layer*> *pLayers) {
  ObjectLayer *pObjectLayer = new ObjectLayer();

  for (TiXmlElement *e = pObjectElement->FirstChildElement();
  e!=NULL;
  e=e->NextSiblingElement()) {
    if ((e->Value() == std::string("object"))) {
      int x,y,width,height,numFrames,callbackID,animSpeed;
      std::string textureID;

      e->Attribute("x", &x);
      e->Attribute("y", &y);
      GameObject *pGameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));

      for (TiXmlElement *properties = e->FirstChildElement();
      properties != NULL;
      properties = properties->NextSiblingElement()) {
        if (properties->Value() == std::string("properties")) {
          for (TiXmlElement *property = properties->FirstChildElement();
          property != NULL;
          property = property->NextSiblingElement()) {
            if (property->Value() == std::string("property")) {
              const char *pTmp = property->Attribute("name");
              if (pTmp == std::string("numFrames")) { property->Attribute("value", &numFrames); }
              if (pTmp == std::string("textureHeight")) { property->Attribute("value", &height); }
              if (pTmp == std::string("textureID")) { textureID = property->Attribute("value"); }
              if (pTmp == std::string("textureWidth")) { property->Attribute("value", &width); }
              if (pTmp == std::string("callbackID")) { property->Attribute("value", &callbackID); }
              if (pTmp == std::string("animSpeed")) { property->Attribute("value", &animSpeed); }
            }
          }
        }
      }
      pGameObject->load(new LoaderParams(x,y,width,height,textureID,numFrames,callbackID,animSpeed));
      pObjectLayer->getGameObject()->push_back(pGameObject);
    }
  }
  pLayers->push_back(pObjectLayer);
}
