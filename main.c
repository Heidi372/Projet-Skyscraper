#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h> 
#include "fonction_SDL.h"
#include "fonction_fichiers.h"


int main()
{
    int nbLig=0,nbCol=0;
    taille_fichier("plateau.txt",&nbLig,&nbCol);
    char** tab=lire_fichier("plateau.txt");
    //printf("Nb ligne:%d",nbLig );
    //printf("Nb ligne:%d",nbCol );
    //tab=modifier_caractere(tab,nbLig,nbCol,'1','2');
    //printf("tableau après modification:\n");
    //afficher_tab_2D(tab,nbLig,nbCol);
    //ecrire_fichier("plateau.txt",tab,nbLig,nbCol);
    //printf("tableau après écriture:\n");
    SDL_Window* fenetre;
    SDL_Renderer* rendu;
    int width,height,acc;
    Uint32 format;
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
    SDL_Texture* sprite=charger_image("pavage.bmp",rendu);
    SDL_Texture* joueur=charger_image("joueur.bmp",rendu);
    SDL_QueryTexture(sprite,&format,&acc,&width,&height);
    width=width/16;
    height=height/10;
    SDL_Rect DestR[160];
    SDL_Rect Src;
    //boucle de jeu
    while(!terminer){
        SDL_RenderClear(rendu);
        //SDL_RenderCopy(rendu,fond,NULL,NULL);

        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                terminer=true;
                break;
            case SDL_KEYDOWN: //appuyer sur une touhe
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE: //appuyer sur Echap
                    case SDLK_q: 
                        terminer=true;
                        break;
                            
                }
                break;
        }
        for(int i=0;i<nbLig;i++){
            for(int j=0;j<nbCol;j++){
                if (tab[i][j]=='1')
                {
                    DestR[i].x=1*width;
                    DestR[i].y=4*height;
                    DestR[i].w=width;
                    DestR[i].h=height;
                    Src.x=width*j;
                    Src.y=height*i;
                    Src.w=width;
                    Src.h=height;
                    SDL_RenderCopy(rendu,sprite,&DestR[i],&Src);
                }
                else if(tab[i][j]=='0'){
                    DestR[i].x=11*width;
                    DestR[i].y=6*height;
                    DestR[i].w=width;
                    DestR[i].h=height;
                    Src.x=width*j;
                    Src.y=height*i;
                    Src.w=width;
                    Src.h=height;
                    SDL_RenderCopy(rendu,sprite,&DestR[i],&Src);

                }
            }
        }


        SDL_RenderPresent(rendu);
        SDL_UpdateWindowSurface(fenetre);
    }
    //Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_DestroyTexture(fond);
    SDL_DestroyTexture(sprite);
    SDL_DestroyRenderer(rendu);
    SDL_Quit();
    desallouer_tab_2D(tab,nbLig);
    return 0;
}
