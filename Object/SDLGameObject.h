#ifndef __SDL_GAME_OBJECT_H__
#define __SDL_GAME_OBJECT_H__

#include "GameObject.h"
#include "../Vector2D.h"

class SDLGameObject : public GameObject {
public:

  SDLGameObject();
  virtual void draw();
  virtual void update();
  virtual void clean();

  void load(const LoaderParams *pParams);

  Vector2D& getPosition() { return m_position; }
  int getWidth() { return m_width; }
  int getHeight() { return m_height; }

protected:

  Vector2D m_position;

  int m_width;
  int m_height;

  int m_currentRow;
  int m_currentFrame;

  int m_numFrames;

  std::string m_textureID;

  Vector2D m_velocity;
  Vector2D m_acceleration;
};

#endif
