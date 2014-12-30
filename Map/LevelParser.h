#ifndef __LEVEL_PARSER_H__
#define __LEVEL_PARSER_H__

#include "Level.h"
#include "TileLayer.h"

#include <tinyxml.h>
#include <vector>

class LevelParser
{
public:

  Level* parseLevel(const char *levelFile);

private:
  /* data */

  void parseTilesets(TiXmlElement *pTilesetRoot,
  std::vector<Tileset> *pTilesets);

  void parseTileLayer(TiXmlElement *pTileElement,
  std::vector<Layer*> *pLayers, const std::vector<Tileset> *pTilesets);

  int m_tileSize;
  int m_width;
  int m_height;
};

#endif /* end of include guard: __LEVEL_PARSER_H__ */
