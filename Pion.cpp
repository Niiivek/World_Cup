#include "Pion.hpp"

Pion::Pion(string n):name(n){
    score=0;
    indice=0;
}

void Pion::deplacement(int move){
    indice+=move;
}

void Pion::augmenter_score(int high){
    score+=high;
}

void Pion::diminuer_score(int lower){
    score-=lower;
}