#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <cmath>
#include <vector>
#include "Box_teams.hpp"
#include "Box_others.hpp"
#include "Pion.hpp"
#include "Board.hpp"
#include "Utility.hpp"
#include "Graphic_Quizz.hpp"
using namespace std;

// Screen dimensions
enum class Turn {
    PLAYER_1,
    PLAYER_2,
    VICTORY
};

class Graphic_Board{
public:
    Graphic_Board(int Width,int Height,int rows,int cols);
    ~Graphic_Board();
    void Init();
    void load_image();
    void load_pawn();
    void init_de();
    void draw_pawn(Pion joueur,int x,int y);
    void init_plateau();
    void draw_de();
    void init_case();
    void draw_countries(Board Plateau,Lucky_box Chance);
    void draw_score(Pion joueur, int y);
    void draw_victory(string winner);
    void lance_quiz(Pion& joueur,int pays,vector <vector<string>> content);
    void game_loop(Board Plateau,Pion & joueur1,Pion & joueur2);
    void update_screen();
    void clean_screen();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font* font;
    SDL_Surface* image;
    SDL_Texture* texture;
    int Window_Width;
    int Window_Height;
    int num_rows;
    int num_cols;
    int audio_rate;
    Uint16 audio_format;
    int audio_buffers;
    Mix_Chunk* correctSound;
    SDL_Texture* pawnTexture;
    vector<string> countries;
    vector<SDL_Rect> buttonRects;
    SDL_Texture* diceTexture;
    SDL_Rect diceRect;
    SDL_Color color;
};
