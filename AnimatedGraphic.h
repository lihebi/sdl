#ifndef __ANIMATED_GRAPHIC_H__
#define __ANIMATED_GRAPHIC_H__

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class AnimatedGraphic : public SDLGameObject
{
public:
  AnimatedGraphic ();
  virtual ~AnimatedGraphic ();

  virtual void load(const LoaderParams *pParams);

  void update();

private:
  /* data */
  int m_animSpeed;
};

class AnimatedGraphicCreator : public BaseCreator {
  GameObject* createGameObject() const {
    return new AnimatedGraphic();
  }
};

#endif /* end of include guard: __ANIMATED_GRAPHIC_H__ */
