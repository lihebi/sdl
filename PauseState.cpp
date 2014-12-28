#include "PauseState.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "InputHandler.h"

const std::string PauseState::s_pauseID = "PAUSE";

PauseState::PauseState() {}

PauseState::~PauseState() {}

void PauseState::s_pauseToMain() {
  TheGame::Instance()->requestChangeState(new MenuState());
}

void PauseState::s_resumePlay() {
  TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->update();
  }
}

void PauseState::render() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->draw();
  }
}

bool PauseState::onEnter() {
  TheTextureManager::Instance()->load("assets/resume.png", "resumebutton",
  TheGame::Instance()->getRenderer());
  TheTextureManager::Instance()->load("assets/main.png", "mainbutton",
  TheGame::Instance()->getRenderer());

  GameObject *button1 = new MenuButton(
  new LoaderParams(200, 100, 200, 80, "mainbutton"), s_pauseToMain);
  GameObject *button2 = new MenuButton(
  new LoaderParams(200, 300, 200, 80, "resumebutton"), s_resumePlay);

  m_gameObjects.push_back(button1);
  m_gameObjects.push_back(button2);
  return true;
}

bool PauseState::onExit() {
  for (int i=0;i<m_gameObjects.size();i++) {
    m_gameObjects[i]->clean();
  }
  m_gameObjects.clear();
  TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
  TheTextureManager::Instance()->clearFromTextureMap("mainbutton");

  TheInputHandler::Instance()->reset();
  return true;
}
