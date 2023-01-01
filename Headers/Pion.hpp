#pragma once
#include<string>
#include<iostream>
using namespace std;
#include "Box.hpp"
#include <list>
#include <vector>
#include <map>

class Pion{
public:
    Pion(string n);
    void deplacement(int move);
    void augmenter_score(int high);
    void diminuer_score(int lower);
    int get_score();
    //Variables
    string name;
    int indice;
    int score;
    //Methods
};