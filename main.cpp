#include <iostream>
#include "Headers/Graphic.hpp"
#include "Headers/Box.hpp"
#include "Headers/Box_teams.hpp"
#include "Headers/Box_others.hpp"
#include "Headers/Pion.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
using namespace std;

vector<vector<string> > read_csv(string csv){
    vector<vector<string> > content;
    vector<string> row;
    string line, words,word;
 
    fstream file (csv, ios::in);
    if(file.is_open()){
        while(getline(file, line)){
            row.clear();
            stringstream str(line);
            while(getline(str, words, ',')){
                for(int i=0;words[i]!='\0';i++){
                    if(words[i]!=';'){
                        word=word+words[i];
                    }else{
                        row.push_back(word);
                        word="";
                    }
                }row.push_back(word);
                content.push_back(row);
            }
        }
    }else
        cout<<"fichier pas ouvert \n";
    return content;
}

int main(int argc, char* argv[]) {
  vector <vector<string> > content=read_csv("team_q.csv");
  Boss_team Case1(content[1][0],content[1][2],content[1][3],content[1][4],content[1][5],content[1][3],5);
  Pion joueur("momo");
  Case1.affiche();
  Graphic test(WINDOW_WIDTH,WINDOW_HEIGHT);
  test.Init();
  test.Load_image();
  test.init_quiz(Case1);
  test.quiz_loop(joueur);
  
  return 0;
}