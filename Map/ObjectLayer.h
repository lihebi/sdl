#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__

#include "Layer.h"
#include <vector>
#include "../Object/GameObject.h"

class ObjectLayer : public Layer
{
public:

  virtual ~ObjectLayer();
  ObjectLayer();

  virtual void update();
  virtual void render();

  std::vector<GameObject*>* getGameObject() {
    return &m_gameObjects;
  }

private:

  std::vector<GameObject*> m_gameObjects;
};

#endif /* end of include guard: __OBJECT_LAYER_H__ */
