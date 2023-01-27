#pragma once
#include<string>
#include<iostream>
#include <time.h>
using namespace std;
#include "Box.hh"

class Lucky_box: public Box{
public:
    Lucky_box();
    int getEffet();
    string getName();
    void affiche() override;
private:
    int effet;
};