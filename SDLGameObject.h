#ifndef __SDL_GAME_OBJECT_H__
#define __SDL_GAME_OBJECT_H__

#include "GameObject.h"
#include "LoaderParams.h"

class SDLGameObject : public GameObject {
public:

  SDLGameObject(const LoaderParams *pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();

protected:

  int m_x;
  int m_y;
  int m_width;
  int m_height;

  int m_currentRow;
  int m_currentFrame;

  std::string m_textureID;
};

#endif
