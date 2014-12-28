#include "Game.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags) {
  SDL_Init(SDL_INIT_EVERYTHING);
  m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
  SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

  m_pGameStateMachine = new GameStateMachine();
  m_pGameStateMachine->changeState(new MenuState());

  m_bHasPendingState = false;
  m_bRunning = true;
  return true;
}

void Game::requestChangeState(GameState *pState) {
  m_bHasPendingState = true;
  m_pPendingState = pState;
}

void Game::render() {
  SDL_RenderClear(m_pRenderer);

  m_pGameStateMachine->render();

  SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
  m_pGameStateMachine->update();
  if (m_bHasPendingState) {
    m_pGameStateMachine->changeState(m_pPendingState);
    m_bHasPendingState = false;
  }
}

void Game::clean() {
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}

void Game::handleEvents() {
  TheInputHandler::Instance()->update();

  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
    m_pGameStateMachine->changeState(new PlayState());
  }
}
