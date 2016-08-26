SDL_PATH=/usr/local
CFLAGS= -std=c++11 -I./includes `sdl2-config --cflags` -I$(SDL_PATH)/include
LDFLAGS=`sdl2-config --static-libs`
CPP_FILES := $(wildcard source/*.cpp)
OBJ_FILES := $(addprefix source/,$(notdir $(CPP_FILES:.cpp=.o)))


source/%.o: source/%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<
  
SDL2Prog: $(OBJ_FILES) 
	$(CXX) $(OBJ_FILES)  -o SDL2Prog $(LDFLAGS)

all: SDL2Prog
clean:
	rm -f SDL2Prog *.o source/*.o
