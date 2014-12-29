#include "MainMenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "StateParser.h"

const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->update();
  }
}

void MainMenuState::render() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->draw();
  }
}

bool MainMenuState::onEnter() {
  std::cout<<"Entering MainMenuState"<<std::endl;

  StateParser stateParser;
  stateParser.parseState("test.xml", s_menuID, &m_gameObjects, &m_textureIDList);
  m_callbacks.push_back(0); // pushback 0 callbackID start from 1
  m_callbacks.push_back(s_menuToPlay);
  m_callbacks.push_back(s_exitFromMenu);

  setCallbacks(m_callbacks);

  return true;
}

bool MainMenuState::onExit() {
  std::cout<<"Exiting MainMenuState"<<std::endl;

  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->clean();
  }
  m_gameObjects.clear();
  for (int i=0;i<m_textureIDList.size();i++) {
    TheTextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
  }

  return true;
}

void MainMenuState::s_menuToPlay() {
  std::cout<<"Play Button Clicked"<<std::endl;
  TheGame::Instance()->requestChangeState(new PlayState());
}

void MainMenuState::s_exitFromMenu() {
  std::cout<<"Exit Button Clicked"<<std::endl;
  TheGame::Instance()->quit();
}

void MainMenuState::setCallbacks(const std::vector<Callback> &callbacks) {
  for (int i=0;i<m_gameObjects.size();i++) {
    if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
      MenuButton *pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
      pButton->setCallback(callbacks[pButton->getCallbackID()]);
    }
  }
}
