#include "Game.h"
#include "LoaderParams.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags) {
  SDL_Init(SDL_INIT_EVERYTHING);
  m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
  m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
  SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

  TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer);

  m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
  m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
  m_bRunning = true;
  return true;
}

void Game::render() {
  SDL_RenderClear(m_pRenderer);

  for (std::vector<GameObject*>::size_type i=0;i!=m_gameObjects.size();i++) {
    m_gameObjects[i]->draw();
  }

  SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
  for (std::vector<GameObject*>::size_type i=0;i!=m_gameObjects.size();i++) {
    m_gameObjects[i]->update();
  }
}

void Game::clean() {
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}

void Game::handleEvents() {
  TheInputHandler::Instance()->update();
}
