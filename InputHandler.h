#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include<vector>
#include<SDL.h>
#include "Vector2D.h"

enum mouse_buttons {
  LEFT = 0,
  MIDDLE = 1,
  RIGHT = 2
};

class InputHandler {
public:

  static InputHandler* Instance() {
    if (s_pInstance == 0) {
      s_pInstance = new InputHandler();
    }
    return s_pInstance;
  }

  void update();

  bool isKeyDown(SDL_Scancode key) const;
  bool getMouseButtonState(int buttonNumber);
  Vector2D *getMousePosition();

private:

  InputHandler();
  ~InputHandler();

  InputHandler(const InputHandler&);
  InputHandler& operator=(const InputHandler&);

  void onKeyDown();
  void onKeyUp();
  void onMouseMove(SDL_Event&);
  void onMouseButtonDown(SDL_Event&);
  void onMouseButtonUp(SDL_Event&);

  const Uint8 *m_keystates;

  std::vector<bool> m_mouseButtonStates;
  Vector2D *m_mousePosition;

  static InputHandler *s_pInstance;
};

typedef InputHandler TheInputHandler;

#endif
