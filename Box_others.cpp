#include "Headers/Box_others.hpp"

Lucky_box::Lucky_box(){
    effet=rand()%6;
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