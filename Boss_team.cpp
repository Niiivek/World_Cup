#include "Boss_team.hpp"

Boss_team::Boss_team(string pays,string q):question(q){
    name=pays;
}

void Boss_team::affiche(){
    cout<<name<<" "<<question<<endl;
}
