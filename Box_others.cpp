#include "Headers/Box_others.hpp"

Lucky_box::Lucky_box(string chance,string e):effet(e){
    name=chance;
}

void Lucky_box::affiche(){
    cout<<name<<" "<<" "<<effet<<endl;
}
