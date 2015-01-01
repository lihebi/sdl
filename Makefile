CC=g++
CFLAGS = -g -Wall `sdl2-config --cflags`
INCLUDES = -I/. -I/usr/local/include
LFLAGS =
LIBS = `sdl2-config --libs` -lSDL2_image -ltinyxml -lz
STATE_SRC = $(addprefix State/, GameStateMachine.cpp MainMenuState.cpp \
	PauseState.cpp GameOverState.cpp PlayState.cpp)
OBJECT_SRC = $(addprefix Object/, SDLGameObject.cpp MenuButton.cpp \
	GameObjectFactory.cpp Player.cpp Enemy.cpp AnimatedGraphic.cpp)
MAP_SRC = $(addprefix Map/, Level.cpp TileLayer.cpp LevelParser.cpp ObjectLayer.cpp)
SRCS = Game.cpp main.cpp TextureManager.cpp InputHandler.cpp \
	StateParser.cpp base64.cpp

SRCS += $(STATE_SRC) $(OBJECT_SRC) $(MAP_SRC)
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
	$(RM) $(OBJS) $(MAIN)
