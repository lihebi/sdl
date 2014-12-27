#include "InputHandler.h"
#include "Game.h"
#include<iostream>

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler() : m_keystates(0) {
}

InputHandler::~InputHandler() {
  delete m_keystates;
}

bool InputHandler::isKeyDown(SDL_Scancode key) const {
  if (m_keystates != 0) {
    if (m_keystates[key] == 1) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

void InputHandler::update() {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_QUIT: {
        TheGame::Instance()->quit();
        break;
      }
      case SDL_KEYDOWN: {
        onKeyDown();
        break;
      }
      case SDL_KEYUP: {
        onKeyUp();
        break;
      }
      default: break;
    }
  }
}

void InputHandler::onKeyDown() {
  m_keystates = SDL_GetKeyboardState(0);
  if (isKeyDown(SDL_SCANCODE_ESCAPE)) {
    TheGame::Instance()->quit();
  }
}

void InputHandler::onKeyUp() {
  m_keystates = SDL_GetKeyboardState(0);
}
