#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->update();
  }
}

void MenuState::render() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->draw();
  }
}

bool MenuState::onEnter() {
  std::cout<<"Entering MenuState"<<std::endl;

  TheTextureManager::Instance()->load("assets/exit.png", "exitbutton",
  TheGame::Instance()->getRenderer());
  TheTextureManager::Instance()->load("assets/button.png", "playbutton",
  TheGame::Instance()->getRenderer());

  GameObject *button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"),
  s_menuToPlay);
  GameObject *button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"),
  s_exitFromMenu);

  m_gameObjects.push_back(button1);
  m_gameObjects.push_back(button2);

  return true;
}

bool MenuState::onExit() {
  std::cout<<"Exiting MenuState"<<std::endl;

  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->clean();
  }
  m_gameObjects.clear();
  TheTextureManager::Instance()->clearFromTextureMap("playbutton");
  TheTextureManager::Instance()->clearFromTextureMap("exitbutton");

  return true;
}

void MenuState::s_menuToPlay() {
  std::cout<<"Play Button Clicked"<<std::endl;
  TheGame::Instance()->getStateMachine()->changeState(new PlayState());
  // TheGame::Instance()->getStateMachine()->changeStateByName("PlayState");
}

void MenuState::s_exitFromMenu() {
  std::cout<<"Exit Button Clicked"<<std::endl;
  TheGame::Instance()->quit();
}
