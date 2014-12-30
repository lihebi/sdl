#ifndef __GAME_OBJECT_FACTORY_H__
#define __GAME_OBJECT_FACTORY_H__

#include<string>
#include<map>
#include "GameObject.h"

class BaseCreator {
public:

  virtual GameObject* createGameObject() const = 0;
  virtual ~BaseCreator() {}
};

class GameObjectFactory
{
public:


  static GameObjectFactory* Instance() {
    if (s_pInstance == NULL) {
      s_pInstance = new GameObjectFactory();
    }
    return s_pInstance;
  }

  bool registerType(std::string typeID, BaseCreator *pCreator) {
    std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);

    if (it != m_creators.end()) {
      delete pCreator;
      return false;
    }

    m_creators[typeID] = pCreator;

    return true;
  }

  GameObject* create(std::string typeID) {
    std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);
    if (it == m_creators.end()) {
      return NULL;
    }

    BaseCreator *pCreator = it->second;
    return pCreator->createGameObject();
  }

private:
  /* data */

  GameObjectFactory () {}
  ~GameObjectFactory () {}

  std::map<std::string, BaseCreator*> m_creators;
  static GameObjectFactory *s_pInstance;
};

typedef GameObjectFactory TheGameObjectFactory;

#endif /* end of include guard: __GAME_OBJECT_FACTORY_H__ */
