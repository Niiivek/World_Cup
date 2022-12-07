#pragma once

#include "Player.hpp"
#include<string>
#include<iostream>
using namespace std;

class Attaquant: public Player{
public:
    Attaquant();
    void print() const;
private:
    string role="attaquant";
    int tir;
    int dribble;
    int vitesse;
};