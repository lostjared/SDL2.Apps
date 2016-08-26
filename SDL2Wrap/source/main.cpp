/* Written by Jared Bruni */


#include<iostream>
#include"SDL2Wrap.h"
const int ScreenWidth = 1280, ScreenHeight = 720;

void rand_pixels(SDL_Texture *tex, SDL_Surface *surface) {
    SDL_LockTexture(tex, 0, &surface->pixels, &surface->pitch);
    for(unsigned int i = 0; i < surface->w; ++i) {
        for(unsigned int z = 0; z < surface->h; ++z) {
            unsigned int *ptr = (unsigned int *)surface->pixels+ (i+z*surface->w);
            *ptr = SDL_MapRGB(surface->format, rand()%255, rand()%255, rand()%255);
        }
    }
    SDL_UnlockTexture(tex);
}


int main() {
	SDLWrap::InitSystem();
	try {
		SDLWrap::SDL_Win window;
		window.createWindow("Hello World",ScreenWidth, ScreenHeight);
		SDLWrap::SDL_Tex texture;
		SDLWrap::SDL_Surf surface;
		texture.createTexture(window.getRenderer(), ScreenWidth, ScreenHeight);
		surface.createSurface(ScreenWidth, ScreenHeight, 32);
		SDL_Event e;
		bool active = true;
		while(active) {
			while(SDL_PollEvent(&e)) {
				switch(e.type) {
				case SDL_KEYDOWN:
					if(e.key.keysym.sym == SDLK_ESCAPE) active = false;
					break;
				case SDL_QUIT:
					active = false;
					break;
				}
			}
			window.clearWindow();
			rand_pixels(texture.getTex(), surface.getSurf());
			window.copyTexture(texture);
			window.present();
		}

	} catch(SDLWrap::Exception &e) {
		std::cerr << e.what() << ": " << SDL_GetError();
	}

	SDLWrap::StopSystem();
    return 0;
}
