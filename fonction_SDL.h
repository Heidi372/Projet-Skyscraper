#ifndef FONCTION_SDL_H
#define FONCTION_SDL_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>

SDL_Texture* charger_image(const char* nomfichier,SDL_Renderer* renderer);

#endif //FONCTION_SDL_H

