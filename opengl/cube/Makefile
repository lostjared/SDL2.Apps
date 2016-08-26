CXX=c++
CXXFLAGS= -I/usr/local/include -I/usr/include -std=c++11  -Wall `sdl2-config --cflags`
LDFLAGS= `sdl2-config --static-libs`  -lGLEW

all:
	$(CXX) gltest.cpp -o gltest $(CXXFLAGS) $(LDFLAGS)
clean:
	rm -f gltest
