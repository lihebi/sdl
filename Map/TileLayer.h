#ifndef __TILE_LAYER_H__
#define __TILE_LAYER_H__

#include "Layer.h"
#include <vector>
#include "Level.h"
#include "../Vector2D.h"

class TileLayer : public Layer
{
public:
  TileLayer (int tileSize, const std::vector<Tileset> &tilesets);

  virtual void update();
  virtual void render();

  void setTileIDs(const std::vector<std::vector<int> > &data) {
    m_tileIDs = data;
  }

  void setTileSize(int tileSize) {
    m_tileSize = tileSize;
  }

  Tileset getTilesetByID(int tileID);

  virtual ~TileLayer ();

private:
  /* data */

  int m_numColumns;
  int m_numRows;
  int m_tileSize;

  const std::vector<Tileset> &m_tilesets;
  std::vector<std::vector<int> > m_tileIDs;

  Vector2D m_position;
  Vector2D m_velocity;


};

#endif /* end of include guard: __TILE_LAYER_H__ */
