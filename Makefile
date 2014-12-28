CC=g++
CFLAGS = -g -Wall `sdl2-config --cflags`
INCLUDES =
LFLAGS =
LIBS = `sdl2-config --libs` -lSDL2_image
SRCS = Game.cpp main.cpp TextureManager.cpp SDLGameObject.cpp Player.cpp\
	InputHandler.cpp GameStateMachine.cpp MenuState.cpp PlayState.cpp\
	MenuButton.cpp PauseState.cpp Enemy.cpp
OBJS = $(SRCS:.c=.o)
MAIN = myprog

.PHONY: all clean


all: $(MAIN)
	@echo Compiled $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
