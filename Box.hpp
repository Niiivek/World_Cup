#pragma once
#include<string>
#include<iostream>
using namespace std;
#include <list>
#include <vector>
#include <map>

class Box{
public:
    //Variables
    string name;
    virtual ~Box() = default;
    virtual void affiche(){cout <<"hi"<<endl;}
    //Methods
};

class Box_team: public Box{
public: 
    list<string> question;
    void affiche() override{cout <<"hi2"<<endl;}  
};

