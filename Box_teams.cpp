#include "Box_teams.hpp"

Boss_team::Boss_team(string pays,string q,string c1,string c2, string c3, string r,int s):question(q),choix1(c1),choix2(c2),choix3(c3),reponse(r),score(s){
    name=pays;
    categorie="boss";
}

void Boss_team::affiche(){
    cout<<name<<" "<<categorie<<" "<<question<<" "<< reponse <<" " << choix1 <<" "<< choix2 << " " <<choix3<<endl;
}

Normal_team::Normal_team(string pays,string q,string c1,string c2, string c3, string r,int s):question(q),choix1(c1),choix2(c2),choix3(c3),reponse(r),score(s){
    name=pays;
    categorie="normal";
}

void Normal_team::affiche(){
    cout<<name<<" "<<categorie<<" "<<question<<" "<< reponse <<" " << choix1 <<" "<< choix2 << " " <<choix3<<endl;
}