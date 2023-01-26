#pragma once
#include<string>
#include<iostream>
#include <time.h>
using namespace std;
#include "Box.hpp"
#include <list>
#include <vector>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Lucky_box: public Box{
public:
    Lucky_box();
    int getEffet();
    string getName();
    void affiche() override;
private:
    int effet;
};