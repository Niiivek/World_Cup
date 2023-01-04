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

class Boss_team: public Box_team{
public:
    Boss_team(string pays,string q,string r,string c1,string c2, string c3,int score);
    void affiche() override;
};

class Normal_team: public Box_team{
public:
    Normal_team(string pays,string q,string r,string c1,string c2, string c3,int score);
    void affiche() override;
};


