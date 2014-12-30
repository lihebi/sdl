#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <string>
#include <vector>
#include "Layer.h"

struct Tileset {
  int firstGridID;
  int tileWidth;
  int tileHeight;
  int spacing;
  int margin;
  int width;
  int height;
  int numColumns;
  std::string name;
};

class Level
{
public:

  void update();
  void render();

  std::vector<Tileset>* getTilesets() {
    return &m_tilesets;
  }

  std::vector<Layer*>* getLayers() {
    return &m_layers;
  }

private:
  /* data */

  std::vector<Tileset> m_tilesets;
  std::vector<Layer*> m_layers;

  friend class LevelParser;

  Level() {}
};

#endif /* end of include guard: __LEVEL_H__ */
