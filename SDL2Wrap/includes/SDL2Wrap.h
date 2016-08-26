#ifndef __SDL2_WRAP__H_
#define __SDL2_WRAP__H_


#include"SDL2/SDL.h"
#include<string>



namespace SDLWrap {


	void InitSystem();
	void StopSystem();

	class Exception {
	public:
		Exception(std::string what) : message(what) {}
		std::string what() const { return message; }
	private:
		std::string message;
	};

	class SDL_Tex {
	public:
		SDL_Tex();
		SDL_Tex(const SDL_Tex &e) = delete;
		SDL_Tex(SDL_Texture *tex) = delete;
		SDL_Tex(const SDL_Tex &&e) = delete;

		SDL_Tex &operator=(const SDL_Tex &e) = delete;
		SDL_Tex &operator=(const SDL_Tex &&e) = delete;

		~SDL_Tex();
		void createTexture(SDL_Renderer *ren, int width, int height);
		void setTexture(bool remove, SDL_Texture *texture);
		void destroy();
		SDL_Texture *getTex() { return tex; }
	private:
		SDL_Texture *tex;
	};

	class SDL_Surf {
	public:
		SDL_Surf();
		SDL_Surf(const SDL_Surf &tex) = delete;
		SDL_Surf(SDL_Surface *surf) = delete;
		SDL_Surf(const SDL_Surf &&tex) = delete;
		~SDL_Surf();
		SDL_Surf &operator=(const SDL_Surf &surface) = delete;
		SDL_Surf &operator=(const SDL_Surf &&surface) = delete;

		void createSurface(int width, int height, int bpp);
		void setSurface(bool remove, SDL_Surface *surface);
		SDL_Surface *getSurf() { return surf; }
		void destroy();
	private:
		SDL_Surface *surf;
	};

	class SDL_Win {
	public:
		SDL_Win();
		~SDL_Win();
		void createWindow(std::string name, int width, int height);
		void pollEvent();
		SDL_Window *getWin() { return window; }
		SDL_Renderer *getRenderer() { return ren; }
		void clearWindow();
		void copyTexture(SDL_Tex &tex);
		void present();
	private:
		SDL_Window *window;
		SDL_Renderer *ren;

	};

}















#endif
