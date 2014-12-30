#include "PauseState.h"
#include "../Object/MenuButton.h"
#include "MainMenuState.h"
#include "../InputHandler.h"
#include "../StateParser.h"

const std::string PauseState::s_pauseID = "PAUSE";

PauseState::PauseState() {}

PauseState::~PauseState() {}

void PauseState::s_pauseToMain() {
  TheGame::Instance()->requestChangeState(new MainMenuState());
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
  StateParser stateParser;
  stateParser.parseState("test.xml", s_pauseID, &m_gameObjects, &m_textureIDList);

  m_callbacks.push_back(0);
  m_callbacks.push_back(s_pauseToMain);
  m_callbacks.push_back(s_resumePlay);

  setCallbacks(m_callbacks);

  return true;
}

void PauseState::setCallbacks(const std::vector<Callback> &callbacks) {
  for (int i=0;i<m_gameObjects.size();i++) {
    if (dynamic_cast<MenuButton*>(m_gameObjects[i])) {
      MenuButton *pButton = dynamic_cast<MenuButton*>(m_gameObjects[i]);
      pButton->setCallback(callbacks[pButton->getCallbackID()]);
    }
  }
}

bool PauseState::onExit() {
  GameState::onExit();
  TheInputHandler::Instance()->reset();
  return true;
}
