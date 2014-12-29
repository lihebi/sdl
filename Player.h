#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Player : public SDLGameObject {
public:

  Player();
  virtual void draw();
  virtual void update();
  virtual void clean();

  void load(const LoaderParams *pParams);

  void handleInput();
};

class PlayerCreator : public BaseCreator {
  GameObject* createGameObject() const {
    return new Player();
  }
};

#endif /* end of include guard: __PLAYER_H__ */
