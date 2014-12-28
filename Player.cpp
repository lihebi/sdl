#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams *pParams) : SDLGameObject(pParams) {
}

void Player::draw() {
  SDLGameObject::draw();
}

void Player::update() {
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
