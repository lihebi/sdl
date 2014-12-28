#ifndef __PAUSE_STATE_H__
#define __PAUSE_STATE_H__

#include "GameState.h"

class GameObject;

class PauseState : public GameState
{
public:
  PauseState ();
  virtual ~PauseState ();

  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateID() const { return s_pauseID; }

private:

  static void s_pauseToMain();
  static void s_resumePlay();

  static const std::string s_pauseID;

  std::vector<GameObject*> m_gameObjects;

};

#endif
