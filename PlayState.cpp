#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->update();
  }
}

void PlayState::render() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->draw();
  }
}

bool PlayState::onEnter() {
  std::cout<<"Entering PlayState"<<std::endl;
  TheTextureManager::Instance()->load("assets/helicopter.png", "helicopter",
  TheGame::Instance()->getRenderer());
  GameObject *player = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));
  m_gameObjects.push_back(player);
  return true;
}

bool PlayState::onExit() {
  std::cout<<"Exiting PlayState"<<std::endl;
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->clean();
  }
  m_gameObjects.clear();
  TheTextureManager::Instance()->clearFromTextureMap("helicopter");
  return true;
}
