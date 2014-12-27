#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include<vector>
#include<SDL.h>

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

private:

  InputHandler();
  ~InputHandler();

  InputHandler(const InputHandler&);
  InputHandler& operator=(const InputHandler&);

  void onKeyDown();
  void onKeyUp();

  const Uint8 *m_keystates;

  static InputHandler *s_pInstance;
};

typedef InputHandler TheInputHandler;

#endif
