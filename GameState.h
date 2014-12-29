#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <string>
#include <vector>
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"

class GameState {
public:

  virtual ~GameState() {}

  virtual void update() = 0;
  virtual void render() = 0;

  virtual bool onEnter() = 0;
  virtual bool onExit() {
    for (int i=0;i<m_gameObjects.size();i++) {
      m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    for (int i=0;i<m_textureIDList.size();i++) {
      TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
    }
    return true;
  }

  virtual std::string getStateID() const = 0;

protected:

  std::vector<std::string> m_textureIDList;
  std::vector<GameObject*> m_gameObjects;
};

#endif
