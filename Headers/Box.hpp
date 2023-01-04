#pragma once
#include<string>
#include<iostream>
using namespace std;
#include <list>
#include <vector>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Box{
public:
    virtual ~Box() = default;
    virtual void affiche(){cout <<"hi"<<endl;}
protected:
    //Variables
    string name;
    //Methods
};

class Box_team: public Box{
public:
    void affiche() override{cout <<"hi2"<<endl;} 
    string getQ();
    string getC();
    vector <string> getChoices();
    string getC1();
    string getC2();
    string getC3();
    string getR();
protected: 
    string categorie;
    string question;
    vector<string> choices;
    string reponse;
    int score;
};




