#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h> 
#include "fonction_SDL.h"
#include "fonction_fichiers.h"


int main()
{
    char** tab=allouer_tab_2D(19,61);
    desallouer_tab_2D(tab,19);
    afficher_tab_2D(tab,19,61);
    taille_fichier("plateau.txt",19,61);
    char read=lire_fichier("plateau.txt");
    SDL_Window* fenetre;
    SDL_Renderer* rendu;
    SDL_Event event;
    bool terminer=false;
    //initialisation de la SDL
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("Erreur de l'initialisation de la SDL%s\n",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    //Création de la fenetre
    fenetre=SDL_CreateWindow("window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,600,SDL_WINDOW_RESIZABLE);
    if(fenetre==NULL){
        printf("Erreur de la creation d'une fenetre:%s\n",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    //creation du rendu
    rendu=SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);
    //Charger image
    SDL_Texture* fond=charger_image("ciel.bmp",rendu);
    //boucle de jeu
    while(!terminer){
        SDL_RenderClear(rendu);
        SDL_RenderCopy(rendu,fond,NULL,NULL);

        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                terminer=true;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        terminer=true;
                        break;
                }
                break;
        }
        SDL_RenderPresent(rendu);
    }
    //Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_DestroyTexture(fond);
    SDL_DestroyRenderer(rendu);
    SDL_Quit();
    return 0;
}
