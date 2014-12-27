#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams *pParams) : SDLGameObject(pParams) {
}

void Player::draw() {
  SDLGameObject::draw();
}

void Player::update() {
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
    m_x--;
  }
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
    m_y++;
  }
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)) {
    m_x++;
  }
  if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W)) {
    m_y--;
  }

  m_currentFrame = int(((SDL_GetTicks() /100 ) % 6));
}

void Player::clean() {}


Enemy::Enemy(const LoaderParams *pParams) : SDLGameObject(pParams) {
}

void Enemy::draw() {
  SDLGameObject::draw();
}

void Enemy::update() {
  // m_x++;
  m_currentFrame = int(((SDL_GetTicks() /100 ) % 6));
}

void Enemy::clean() {}
