#include "Game.h"
#include<iostream>

int main(int argc, char** argv) {
  TheGame::Instance()->init("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  while(TheGame::Instance()->running()) {
    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();

    SDL_Delay(10);
  }
  std::cout<<"cleaning"<<std::endl;
  TheGame::Instance()->clean();
  return 0;
}
