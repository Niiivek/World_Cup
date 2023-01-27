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

TEST_CASE("1: Création du plateau de jeu")
{
  Pion joueur("name");
  int x=0;
  REQUIRE(x==0);
}

/*TEST_CASE("2: Tableau2D with string")
{
  Tableau2D<std::string> tab(4,4);
  tab(1,3) = "ABC";
  REQUIRE(tab(1,3)== "ABC");
  REQUIRE(tab(3,3)== "");
  std::cout << " ----------- Tableau string --------------" << std::endl;
  std::cout << tab << std::endl;
}*/
