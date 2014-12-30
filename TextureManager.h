#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include<map>
#include<string>
#include<iostream>
#include<SDL.h>

class TextureManager {
public:

  static TextureManager* Instance() {
    if (s_pInstance == NULL) {
      s_pInstance = new TextureManager();
    }
    return s_pInstance;
  }

  bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);
  void draw(std::string id, int x, int y, int width, int height,
  SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  void drawFrame(std::string id, int x, int y, int width, int height,
  int currentRow, int currentFrame, SDL_Renderer *pRenderer,
  SDL_RendererFlip flip=SDL_FLIP_NONE);

  void drawTile(std::string id, int margin, int spacing, int x, int y,
  int width, int height, int currentRow, int currentFrame,
  SDL_Renderer *pRenderer);

  std::map<std::string, SDL_Texture*> m_textureMap;

  void clearFromTextureMap(std::string id);

private:
  TextureManager() {}
  static TextureManager *s_pInstance;
};

typedef TextureManager TheTextureManager;

#endif
