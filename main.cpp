#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Box.hpp"
#include "Box_teams.hpp"
#include "Box_others.hpp"
#include "Pion.hpp"
#include <iostream>
#include <string>
#include <list>
using namespace std;

// Screen dimensions
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;


int main() {
    /*if(0){

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        // Handle error
        std::cout << "SDL_Init() failed: " << SDL_GetError() << std::endl;
        return 1;
    }
    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        // Handle error
        std::cout << "IMG_Init() failed: " << IMG_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create the game window
    SDL_Window* window = SDL_CreateWindow("Board Game",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH,
                              SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);

    // Check if the window was created successfully
    if (window == NULL)
    {
        std::cout << "SDL_CreateWindow() failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);

    // Check if the renderer was created successfully
    if (renderer == NULL)
    {
        std::cout << "SDL_CreateRenderer() failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Surface* imageSurface = IMG_Load("image/Monopoly.jpg");
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer,imageSurface);

    SDL_Event e;
    bool end=true;
    while(end!=false){
       while(SDL_PollEvent(&e)){
            switch(e.type){
            case SDL_QUIT:
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                end=false;
                break;
            default: {}
            }
        }
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    // Destroy the window and the renderer
    SDL_DestroyTexture(imageTexture);
    SDL_FreeSurface(imageSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit the SDL library
    SDL_Quit();
    }*/
    
    Boss_team Case1("chine","comment vas tu",10);
    Normal_team Case2("france","hi",5);
    Lucky_box Case3("Chance","Tu est qualifié à la phase suivante");
    vector <Box*> Board;
    Board.push_back(&Case1);
    Board.push_back(&Case2);
    Board.push_back(&Case3);
    Board[0]->affiche();
    Board[1]->affiche();
    Board[2]->affiche();

    Pion joueur1("mm");
    return 0;

}
