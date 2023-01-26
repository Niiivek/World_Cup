#include <iostream>
#include "Headers/Graphic_Quizz.hpp"
#include "Headers/Graphic_Board.hpp"
#include "Headers/Box.hpp"
#include "Headers/Box_teams.hpp"
#include "Headers/Box_others.hpp"
#include "Headers/Pion.hpp"
#include "Headers/Board.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <cmath>
using namespace std;
const int NUM_COLS = 5;
const int NUM_ROWS = 5;

int main(int argc, char* argv[]) {
  srand(time(NULL));
  Board Plateau("Sources/team_q.csv",16);
  Pion joueur1("Joueur 1");
  Pion joueur2("Joueur 2");
  Graphic_Board game(WINDOW_WIDTH,WINDOW_HEIGHT,NUM_ROWS,NUM_COLS);
  game.Init();
  game.load_image();
  game.load_pawn();
  game.game_loop(Plateau,joueur1,joueur2);
  return 0;
}