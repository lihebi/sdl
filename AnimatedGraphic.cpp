#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams *pParams, int animSpeed) :
SDLGameObject(pParams), m_animSpeed(animSpeed) {
  m_numFrames = 6;
  m_currentFrame = 1;
}

AnimatedGraphic::~AnimatedGraphic() {}

void AnimatedGraphic::update() {
  m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}
