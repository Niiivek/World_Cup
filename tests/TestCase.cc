// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Box_lucky.hpp"
#include "Box.hpp"
#include <iostream>
#include <string>

TEST_CASE("1: Création du plateau de jeu")
{
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
