#include "Headers/Box_teams.hpp"

Boss_team::Boss_team(string pays,string q,string r,string c1,string c2, string c3,int s){
    name=pays;
    categorie="boss";
    question=q;
    choices={c1,c2,c3};
    reponse=r;
    score=s;
}

void Boss_team::affiche(){
    cout<<name<<" "<<categorie<< " "<<question<<" "<<reponse<<" "<<choices[0]<<" "<<choices[1]<<" "<<choices[2]<<endl;
}

Normal_team::Normal_team(string pays,string q,string r,string c1,string c2, string c3,int s){
    name=pays;
    categorie="normal";
    question=q;
    choices={c1,c2,c3};
    reponse=r;
    score=s;
}

void Normal_team::affiche(){
    cout<<name<<" "<<categorie<<" "<<question<<" "<< reponse<<" "<< choices[0]<<" "<<choices[1]<<" "<<choices[2]<<endl;
}

string Box_team::getQ(){
    return question;
}

vector <string> Box_team::getChoices(){
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