#pragma once
#include<string>
#include<iostream>
using namespace std;
#include <list>
#include <vector>
#include <map>

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
    string getC1();
    string getC2();
    string getC3();
    string getR();
protected: 
    string categorie;
    string question;
    string choix1;
    string choix2;
    string choix3;
    string reponse;
    int score;
};




