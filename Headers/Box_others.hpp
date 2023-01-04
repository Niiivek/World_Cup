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

class Empty_box: public Box{
public:
    
    void affiche() override;
private:
};

class Lucky_box: public Box{
public:
    Lucky_box(string chance,string e);
    void affiche() override;
private:
    string effet;
};