#include "GameOverState.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuState.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "LoaderParams.h"
#include "MenuButton.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

GameOverState::GameOverState() {}

GameOverState::~GameOverState() {}

void GameOverState::s_gameOverToMain() {
  TheGame::Instance()->requestChangeState(new MenuState());
}

void GameOverState::s_restartPlay() {
  TheGame::Instance()->requestChangeState(new PlayState());
}

bool GameOverState::onEnter() {
  TheTextureManager::Instance()->load("assets/gameover.png", "gameovertext",
  TheGame::Instance()->getRenderer());
  TheTextureManager::Instance()->load("assets/main.png", "mainbutton",
  TheGame::Instance()->getRenderer());
  TheTextureManager::Instance()->load("assets/restart.png", "restartbutton",
  TheGame::Instance()->getRenderer());

  GameObject *gameOverText = new AnimatedGraphic(
  new LoaderParams(200, 100, 190, 30, "gameovertext"), 2);
  GameObject *button1 = new MenuButton(
  new LoaderParams(200, 200, 200, 80, "mainbutton"), s_gameOverToMain);
  GameObject *button2 = new MenuButton(
  new LoaderParams(200, 300, 200, 80, "restartbutton"), s_restartPlay);

  m_gameObjects.push_back(gameOverText);
  m_gameObjects.push_back(button1);
  m_gameObjects.push_back(button2);

  return true;
}

void GameOverState::update() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->update();
  }
}

void GameOverState::render() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->draw();
  }
}

bool GameOverState::onExit() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->clean();
  }
  m_gameObjects.clear();
  TheTextureManager::Instance()->clearFromTextureMap("gameovertext");
  TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
  TheTextureManager::Instance()->clearFromTextureMap("restartbutton");
  return true;
}
