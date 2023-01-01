#include "Headers/Box_teams.hpp"

Boss_team::Boss_team(string pays,string q,string c1,string c2, string c3, string r,int s){
    name=pays;
    categorie="boss";
    question=q;
    choix1=c1;
    choix2=c2;
    choix3=c3;
    reponse=r;
    score=s;
}

void Boss_team::affiche(){
    cout<<name<<" "<<categorie<<" "<<question<<" "<< reponse <<" " << choix1 <<" "<< choix2 << " " <<choix3<<endl;
}

Normal_team::Normal_team(string pays,string q,string c1,string c2, string c3, string r,int s){
    name=pays;
    categorie="normal";
    question=q;
    choix1=c1;
    choix2=c2;
    choix3=c3;
    reponse=r;
    score=s;
}

void Normal_team::affiche(){
    cout<<name<<" "<<categorie<<" "<<question<<" "<< reponse <<" " << choix1 <<" "<< choix2 << " " <<choix3<<endl;
}

string Box_team::getQ(){
    return question;
}

string Box_team::getC1(){
    return choix1;
}

string Box_team::getC2(){
    return choix2;
}

string Box_team::getC3(){
    return choix3;
}

string Box_team::getR(){
    return reponse;
}