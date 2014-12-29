#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Enemy : public SDLGameObject {
public:

  Enemy();

  void load(const LoaderParams *pParams);

  virtual void draw();
  virtual void update();
  virtual void clean();
};

class EnemyCreator : public BaseCreator {
  GameObject* createGameObject() const {
    return new Enemy();
  }
};

#endif
