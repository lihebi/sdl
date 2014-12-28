#ifndef __ANIMATED_GRAPHIC_H__
#define __ANIMATED_GRAPHIC_H__

#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
  AnimatedGraphic (const LoaderParams *pParams, int animSpeed);
  virtual ~AnimatedGraphic ();

  void update();

private:
  /* data */
  int m_animSpeed;
};

#endif /* end of include guard: __ANIMATED_GRAPHIC_H__ */
