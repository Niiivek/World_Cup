#pragma once
#include<string>
#include<iostream>
using namespace std;
#include "Box.hh"

class Pion{
public:
    Pion(string n);
    void deplacement(int move,int limit_x,int limit_y);
    void augmenter_indice(int move,int indice_limit);
    void augmenter_score(int high);
    void diminuer_score(int lower);
    int get_score();
    int get_indice();
    int get_x();
    int get_y();
    string get_name();
    friend ostream& operator<<(ostream& os,const Pion& pion);
private:
    string name;
    int x;
    int y;
    int score;
    int indice;
};