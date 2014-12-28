#ifndef __MENU_STATE_H__
#define __MENU_STATE_H__

#include "GameState.h"
#include "GameObject.h"

class MenuState : public GameState {
public:

  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateID() const { return s_menuID; }

private:

  static const std::string s_menuID;

  std::vector<GameObject*> m_gameObjects;
};

#endif
