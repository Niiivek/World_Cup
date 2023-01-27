#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <sstream>
#include <fstream>
#include <string>
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
    vector<vector<string>> getContent();
    int getLucky_indice();
    friend ostream& operator<<(ostream& os,const Board& plateau);
private:
    vector <string> board;
    vector<vector<string> > content;
    vector <int> tab;
    int lucky_indice;
};