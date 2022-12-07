#include "Attaquant.hpp"

Attaquant::Attaquant(){
    tir=rand()%STAT_MAX;
    dribble=rand();
    vitesse=rand();
}

void Attaquant::print() const{
    cout<< tir<<endl;
}