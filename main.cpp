#include "Game.h"
#include<iostream>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char** argv) {
  Uint32 frameStart, frameTime;
  TheGame::Instance()->init("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  while(TheGame::Instance()->running()) {
    frameStart = SDL_GetTicks();

    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();

    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < DELAY_TIME) {
      SDL_Delay((int)(DELAY_TIME - frameTime));
    }
  }
  std::cout<<"cleaning"<<std::endl;
  TheGame::Instance()->clean();
  return 0;
}
