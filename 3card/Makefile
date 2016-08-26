### be sure to set SDL_PATH to the path of SDL2

CXX=c++
SDL_PATH=/opt/local/sdl
CPP_FLAGS= -std=c++11 -stdlib=libc++ -Wall
CXX_FLAGS= -I/usr/include -I/usr/local/include  `sdl2-config --cflags`
LD_FLAGS= `freetype-config --libs` `sdl2-config --static-libs` -lSDL2_ttf

all:
	$(CXX) $(CPP_FLAGS) 3card.cpp -c -o 3card.o $(CXX_FLAGS)
	$(CXX) $(CPP_FLAGS) 3card.o -o 3card-prog $(LD_FLAGS)
clean:
	rm -f 3card-prog *.o
