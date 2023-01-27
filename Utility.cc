#include "Headers/Utility.hh"

int convert_board(int x){ // Convertisseur de case pour notre plateau de jeu
  if(x==5)
    return 15;
  if(x==6)
    return 5;
  if(x==7)
    return 14;
  if(x==8)
    return 6;
  if(x==9)
    return 13;
  if(x==10)
    return 7;
  if(x==11)
    return 12;
  if(x==12)
    return 11;
  if(x==13)
    return 10;
  if(x==14)
    return 9;
  if(x==15)
    return 8;
  return x;
}