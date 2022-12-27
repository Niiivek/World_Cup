#pragma once
#include<string>
#include<iostream>
using namespace std;
#include "Box.hpp"
#include <list>
#include <vector>
#include <map>

class Empty_box: public Box{
public:
    
    void affiche() override;
private:
};

class Lucky_box: public Box{
public:
    Lucky_box(string chance,string effet);
    void affiche() override;
private:
    string effet;
};