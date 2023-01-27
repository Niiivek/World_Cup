#include "Headers/Box_others.hpp"

Lucky_box::Lucky_box(){ // constructeur de la case chance qui donne donne un bonus aléatoire
    effet=rand()%6+1;
    name="Chance";
}

void Lucky_box::affiche(){
    cout<<"Case "+name+": gagne automatiquement "+to_string(effet)+" points"<<endl;
}

int Lucky_box::getEffet(){
    return effet;
}

string Lucky_box::getName(){
    return name;
}