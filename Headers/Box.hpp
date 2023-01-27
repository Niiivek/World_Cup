#pragma once
#include<string>
#include<iostream>
using namespace std;
#include <map>

class Box{
public:
    virtual ~Box() = default;
    virtual void affiche(){cout <<"hi"<<endl;}
protected:
    string name;
};

class Box_team: public Box{
public:
    void affiche() override{cout <<"hi2"<<endl;} 
    string getQ();
    map <int,string> getChoices();
    string getC1();
    string getC2();
    string getC3();
    string getR();
    int getScore();
    int getMalus();
protected: 
    string categorie;
    string question;
    map <int,string> choices;
    string reponse;
    int score;
    int malus;
};




