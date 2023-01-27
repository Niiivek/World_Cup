#include "Headers/Pion.hh"

Pion::Pion(string n):name(n){
    score=0;
    x=0;
    y=0;
    indice=0;
}

void Pion::deplacement(int move,int limit_x,int limit_y){ // déplacement au sein du plateau 
    if(x==0){ //horizontale haute
        //cout << "horizontale haute"<<endl;
        while(y!=limit_y-1 && move!=0){
            y++;
            move--;
        }x+=move;
    }else if(x==limit_x-1){ //horizontale basse
        //cout << "horizontale basse"<<endl;
        while(y!=0 && move!=0){
            y--;
            move--;
        }x-=move;
    }else if(y==0){ //verticale gauche
        //cout << "verticale gauche"<<endl;
        while(x!=0 && move!=0){
            x--;
            move--;
        }y+=move;
    }else{//verticale droite
        //cout << "verticale droite"<<endl;
        while(x!=limit_x-1 && move!=0){
            x++;
            move--;
        }y-=move;
    }
}

void Pion::augmenter_indice(int move, int indice_limit){ // ajouter l'indice pour savoir où on est avec boucle 
    if(indice+move>indice_limit){
        while(indice!=indice_limit){
            indice++;
            move--;
        }indice=-1;
        indice+=move;
    }else{
        indice+=move;
    }
}

void Pion::augmenter_score(int high){
    score+=high;
}

void Pion::diminuer_score(int lower){
    score-=lower;
}

int Pion::get_score(){
    return score;
}

int Pion::get_indice(){
    return indice;
}

int Pion::get_x(){
    return x;
}

int Pion::get_y(){
    return y;
}

string Pion::get_name(){
    return name;
}

ostream& operator<<(ostream& os, const Pion& pion){ // surchage d'opérateur permettant l'affichage des attributs du pion
    os << pion.name << " x:" << pion.x << " y:" << pion.y << " score:" << pion.score << " indice:" << pion.indice;
    return os;
}