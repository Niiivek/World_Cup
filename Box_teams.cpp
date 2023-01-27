#include "Headers/Box_teams.hpp"

//constructeur de nos cases, affichages et getteurs
Boss_team::Boss_team(string pays,string q,string r,string c1,string c2, string c3){
    name=pays;
    categorie="boss";
    question=q;
    choices={{0,c1}, {1,c2}, {2,c3}};
    reponse=r;
    score=5;
    malus=2;
}

void Boss_team::affiche(){
    cout<<name<<" "<<categorie<< " "<<question<<" "<<reponse<<" "<<choices[0]<<" "<<choices[1]<<" "<<choices[2]<<endl;
}

Normal_team::Normal_team(string pays,string q,string r,string c1,string c2, string c3){
    name=pays;
    categorie="normal";
    question=q;
    choices={{0,c1}, {1,c2}, {2,c3}};
    reponse=r;
    score=2;
    malus=1;
}

void Normal_team::affiche(){
    cout<<name<<" "<<categorie<<" "<<question<<" "<< reponse<<" "<< choices[0]<<" "<<choices[1]<<" "<<choices[2]<<endl;
}

string Box_team::getQ(){
    return question;
}

map <int,string> Box_team::getChoices(){
    return choices;
}

string Box_team::getC1(){
    return choices[0];
}

string Box_team::getC2(){
    return choices[1];
}

string Box_team::getC3(){
    return choices[2];
}

string Box_team::getR(){
    return reponse;
}

int Box_team::getScore(){
    return score;
}

int Box_team::getMalus(){
    return malus;
}