#include "fonction_SDL.h"

SDL_Texture* charger_image(const char* nomfichier,SDL_Renderer* renderer){
	SDL_Surface* surface=SDL_LoadBMP(nomfichier);
	SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface (surface);
	return texture;
}