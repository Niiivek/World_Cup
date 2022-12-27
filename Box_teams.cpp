#include "Box_teams.hpp"

Boss_team::Boss_team(string pays,string q,int s):question(q),score(s){
    name=pays;
    categorie="boss";
}

void Boss_team::affiche(){
    cout<<name<<" "<<categorie<<" "<<question<<endl;
}

Normal_team::Normal_team(string pays,string q,int s):question(q),score(s){
    name=pays;
    categorie="normal";
}

void Normal_team::affiche(){
    cout<<name<<" "<<categorie<<" "<<question<<endl;
}