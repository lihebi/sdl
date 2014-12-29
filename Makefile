CC=g++
CFLAGS = -g -Wall `sdl2-config --cflags`
INCLUDES = -I/usr/local/include
LFLAGS =
LIBS = `sdl2-config --libs` -lSDL2_image -ltinyxml
SRCS = Game.cpp main.cpp TextureManager.cpp SDLGameObject.cpp\
	InputHandler.cpp \
	MenuButton.cpp GameObjectFactory.cpp StateParser.cpp\
	GameStateMachine.cpp MainMenuState.cpp PauseState.cpp GameOverState.cpp PlayState.cpp\
	Player.cpp Enemy.cpp AnimatedGraphic.cpp
OBJS = $(SRCS:.cpp=.o)
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
