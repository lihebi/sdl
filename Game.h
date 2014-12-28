#ifndef __GAME_H__
#define __GAME_H__

#include<SDL.h>
#include<vector>
#include<iostream>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "GameStateMachine.h"

class Game {
public:


  static Game* Instance() {
    if (s_pInstance == 0) {
      s_pInstance = new Game();
      return s_pInstance;
    }
    return s_pInstance;
  }

  bool init(const char *title, int xpos, int ypos, int width, int height, int flags);
  void render();
  void update();
  void handleEvents();
  void clean();

  bool running() {
    return m_bRunning;
  }

  int m_currentFrame;
  SDL_Renderer* getRenderer() const { return m_pRenderer;}
  void quit() { std::cout<<"quit"<<std::endl;m_bRunning=false;}

  GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
  void requestChangeState(GameState *pState);

private:
  Game() {}
  ~Game() {}
  static Game *s_pInstance;


  SDL_Window *m_pWindow;
  SDL_Renderer *m_pRenderer;
  bool m_bRunning;
  std::vector<GameObject*> m_gameObjects;

  GameStateMachine *m_pGameStateMachine;

  bool m_bHasPendingState;
  GameState *m_pPendingState;
};

typedef Game TheGame;

#endif
