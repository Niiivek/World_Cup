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
    Boss_team(string pays,string q);
    void affiche() override;
private:
    string question;
};