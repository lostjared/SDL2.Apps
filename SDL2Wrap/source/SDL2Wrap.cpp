#include"SDL2Wrap.h"

namespace SDLWrap {


	void InitSystem() {
		SDL_Init(SDL_INIT_VIDEO);
	}

	void StopSystem() {
		SDL_Quit();
	}

	SDL_Tex::SDL_Tex() : tex(0) {}

	SDL_Tex::~SDL_Tex() {
		destroy();
	}

	void SDL_Tex::createTexture(SDL_Renderer *ren, int width, int height) {
		tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
		if(tex == 0) {
			throw Exception("Could not create texture");
		}
	}

	void SDL_Tex::setTexture(bool remove, SDL_Texture *texture) {
		if(remove == true) destroy();
		tex = texture;

	}

	void SDL_Tex::destroy() {
		if(tex != 0) {
			SDL_DestroyTexture(tex);
			tex = 0;
		}
	}


	SDL_Surf::SDL_Surf() : surf(0) {}

	SDL_Surf::~SDL_Surf() {
		destroy();
	}

	void SDL_Surf::destroy() {
		if(surf != 0) {
			SDL_FreeSurface(surf);
			surf = 0;
		}
	}

	void SDL_Surf::createSurface(int width, int height, int bpp) {
		surf = SDL_CreateRGBSurfaceFrom(NULL, width, height, bpp, 0, 0x00FF0000, 0x0000FF00,0x000000FF,0xFF000000);
		if(surf == 0) {
			throw Exception("Could not create surface!");
		}
	}

	void SDL_Surf::setSurface(bool remove, SDL_Surface *surface) {
		if(remove == true) destroy();
		surf = surface;
	}



	SDL_Win::SDL_Win() : window(0), ren(0) {

	}

	SDL_Win::~SDL_Win() {
		if(window != 0) {
			SDL_DestroyWindow(window);
			window = 0;
		}

	}

	void SDL_Win::createWindow(std::string title, int width, int height) {
		window = SDL_CreateWindow(title.c_str(), 0, 0, width, height, SDL_WINDOW_SHOWN);
		ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if(ren == 0) {
			throw Exception("Could not init Renderer");
		}

	}

	void SDL_Win::clearWindow() {
		SDL_RenderClear(ren);
	}
	void SDL_Win::copyTexture(SDL_Tex &tex) {
		SDL_RenderCopy(ren, tex.getTex(), 0, 0);

	}
	void SDL_Win::present() {
		SDL_RenderPresent(ren);
	}

	void SDL_Win::pollEvent() {

	}

}
