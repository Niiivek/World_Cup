#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <cmath>
#include <vector>
#include "Box_teams.hpp"
#include "Pion.hpp"
using namespace std;

// Screen dimensions
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 500;
enum class State {
    SHOW_QUESTION,
    SHOW_RESULT
};

class Graphic_Quizz{
public:
    Graphic_Quizz(int Width,int Height);
    ~Graphic_Quizz();
    void Init();
    void load_image();
    void init_quiz(Box_team pays);
    void draw_question();
    void draw_buttons();
    void draw_result(string resultText,SDL_Texture* resultTexture);
    void draw_score(Pion joueur);
    void quiz_loop(Pion & joueur,Box_team pays);
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
    string question;
    string answer;
    map<int,string> choices;
    vector<SDL_Rect> buttonRects;

};
