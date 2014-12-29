#ifndef __GAME_OVER_STATE_H__
#define __GAME_OVER_STATE_H__

#include "GameState.h"
#include "MenuState.h"

class GameObject;

class GameOverState : public MenuState
{
public:
  GameOverState ();
  virtual ~GameOverState ();

  virtual void update();
  virtual void render();

  virtual bool onEnter();
  virtual bool onExit();

  virtual std::string getStateID() const { return s_gameOverID; }

  virtual void setCallbacks(const std::vector<Callback> &callbacks);

private:
  /* data */

  static void s_gameOverToMain();
  static void s_restartPlay();

  static const std::string s_gameOverID;
};

#endif /* end of include guard: __GAME_OVER_STATE_H__ */
