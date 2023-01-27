// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Headers/Box.hh"
#include "Headers/Box_teams.hh"
#include "Headers/Box_others.hh"
#include "Headers/Pion.hh"
#include "Headers/Board.hh"
#include <iostream>
#include <string>
#include <time.h>

TEST_CASE("1: Pion")
{
  Pion joueur("Joueur 1");
  REQUIRE(joueur.get_name()=="Joueur 1");
  joueur.augmenter_score(10);
  joueur.augmenter_indice(2,5);
  REQUIRE(joueur.get_score()==10);
  REQUIRE(joueur.get_indice()==2);
  joueur.deplacement(2,5,5);
  std::stringstream ss;
  ss << joueur;
  REQUIRE(ss.str()=="Joueur 1 x:0 y:2 score:10 indice:2");

}

TEST_CASE("2: Cases")
{
  Boss_team Case1("France","Quelle est la capitale de la France ?","Paris","Bordeaux","Marseille","Paris");
  REQUIRE(Case1.getC1()=="Bordeaux");
  REQUIRE(Case1.getR()=="Paris");
  REQUIRE(Case1.getQ()=="Quelle est la capitale de la France ?");
  REQUIRE(Case1.getScore()==5);
}

TEST_CASE("3: Plateau de jeu"){
  srand(time(NULL));
  Board plateau("../Sources/team_q.csv",15);
  REQUIRE(plateau.getBoard().size()==15);
  cout << plateau; // des pays différents à chaque fois donc c'est bon
}
