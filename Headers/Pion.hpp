#pragma once
#include<string>
#include<iostream>
using namespace std;
#include "Box.hpp"
#include <list>
#include <vector>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Pion{
public:
    Pion(string n);
    void deplacement(int move,int limit_x,int limit_y);
    void augmenter_score(int high);
    void diminuer_score(int lower);
    int get_score();
    int get_x();
    int get_y();
    //Variables
    string name;
    int x;
    int y;
    int score;
    //Methods
};