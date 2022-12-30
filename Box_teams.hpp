#pragma once
#include<string>
#include<iostream>
using namespace std;
#include "Box.hpp"
#include <list>
#include <vector>
#include <map>

class Boss_team: public Box_team{
public:
    Boss_team(string pays,string q,string c1,string c2, string c3, string r,int score);
    void affiche() override;
private:
    string question;
    string choix1;
    string choix2;
    string choix3;
    string reponse;
    int score;
};

class Normal_team: public Box_team{
public:
    Normal_team(string pays,string q,string c1,string c2, string c3, string r,int score);
    void affiche() override;
private:
    string question;
    string choix1;
    string choix2;
    string choix3;
    string reponse;
    int score;
};