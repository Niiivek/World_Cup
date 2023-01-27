#pragma once
#include<string>
#include<iostream>
using namespace std;
#include "Box.hh"

class Boss_team: public Box_team{
public:
    Boss_team(string pays,string q,string r,string c1,string c2, string c3);
    void affiche() override;
};

class Normal_team: public Box_team{
public:
    Normal_team(string pays,string q,string r,string c1,string c2, string c3);
    void affiche() override;
};


