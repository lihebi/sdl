#ifndef __GAME_OVER_STATE_H__
#define __GAME_OVER_STATE_H__

#include "GameState.h"

class GameObject;

class GameOverState : public GameState
{
public:
  GameOverState ();
  virtual ~GameOverState ();

  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateID() const { return s_gameOverID; }

private:
  /* data */

  static void s_gameOverToMain();
  static void s_restartPlay();

  static const std::string s_gameOverID;

  std::vector<GameObject*> m_gameObjects;
};

#endif /* end of include guard: __GAME_OVER_STATE_H__ */
