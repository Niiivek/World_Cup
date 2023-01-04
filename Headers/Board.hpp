#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>
#include "Box_teams.hpp"
#include "Pion.hpp"
#include "Box.hpp"
#include "Box_teams.hpp"
#include "Box_others.hpp"
using namespace std;

const int BOARD_WIDTH = 1000;
const int BOARD_HEIGHT = 500;

class Board{
public:
    Board(string csv,int nb_cases);
    vector<vector<string> > read_csv(string csv);
    vector <int> random(int n,int max);
    int appartient(int a,vector <int> tab);
    void affiche_random();
    vector<string> getBoard();
    vector<int> getRandom();
private:
    vector <string> board;
    vector<vector<string> > content;
    vector <int> tab;

};