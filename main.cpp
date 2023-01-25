#include <iostream>
#include "Headers/Graphic.hpp"
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

int convert_board(int x){
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
void lance_quiz(int width,int height,Pion& joueur,int pays,vector <vector<string> > content){
  if(content[pays][1]=="Boss"){
    Boss_team Case1(content[pays][0],content[pays][2],content[pays][3],content[pays][4],content[pays][5],content[pays][6]);
    Graphic test(width,height);
    test.Init();
    test.load_image();
    test.init_quiz(Case1);
    test.quiz_loop(joueur,Case1);
  }else{
    Normal_team Case1(content[pays][0],content[pays][2],content[pays][3],content[pays][4],content[pays][5],content[pays][6]);
    Graphic test(width,height);
    test.Init();
    test.load_image();
    test.init_quiz(Case1);
    test.quiz_loop(joueur,Case1);
  }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    vector <vector<string> > content=read_csv("team_q.csv");
  Board Plateau("team_q.csv",16);
  Plateau.affiche_random();
  Pion joueur1("Joueur 1");
  Pion joueur2("Joueur 2");
  cout<<Plateau<<endl;
  /*for(int i=0;i<32;i++){
    lance_quiz(WINDOW_WIDTH,WINDOW_HEIGHT,joueur,Plateau.getRandom()[i],content);
  }*/
  //lance_quiz(WINDOW_WIDTH,WINDOW_HEIGHT,joueur,Plateau.getRandom()[0],content);
  // Initialize SDL
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Color color = {0, 0, 0, 0}; // Black
  // Create the window and renderer
  SDL_Window* window = SDL_CreateWindow("Board Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
   // Load an image
  SDL_Surface* image = IMG_Load("image/F.png");
  if (image == nullptr) {
    cerr << "Error loading image: " << IMG_GetError() << endl;
    return 1;
  }

  // Create a texture from the image
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_FreeSurface(image);
  if (texture == nullptr) {
    cerr << "Error creating texture: " << SDL_GetError() << endl;
    return 1;
  }
   // Initialize the TTF library
if (TTF_Init() != 0) {
  cerr << "Error initializing TTF: " << TTF_GetError() << endl;
  return 1;
}
// Load the pawn image
  SDL_Surface* pawnImage = IMG_Load("image/pion.png.jpeg");
  if (pawnImage == nullptr) {
    cerr << "Error loading image: " << IMG_GetError() << endl;
    return 1;
  }
  // Create a texture from the pawn image
  SDL_Texture* pawnTexture = SDL_CreateTextureFromSurface(renderer, pawnImage);
  SDL_FreeSurface(pawnImage);
  if (pawnTexture == nullptr) {
    cerr << "Error creating texture: " << SDL_GetError() << endl;
    return 1;
  }

  // Initialize the position of the pawn
  int deplacement=0;

  // Set up the audio device
int audio_rate = 22050;
Uint16 audio_format = AUDIO_S16SYS;
int audio_channels = 2;
int audio_buffers = 4096;
if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
  cerr << "Error opening audio device: " << Mix_GetError() << endl;
  return 1;
}
// Load the sound effect for correct answers
Mix_Chunk* correctSound = Mix_LoadWAV("song/IHoqpnFWqJn_VEGEDREAM---RAMENEZ-LA-COUPE-A-LA-MAISON.mp3");

enum class Turn {
    PLAYER_1,
    PLAYER_2
};

Turn turn=Turn::PLAYER_1;
// Load a font
TTF_Font* font = TTF_OpenFont("arial.ttf", 27);
if (font == nullptr) {
  cerr << "Error loading font: " << TTF_GetError() << endl;
  return 1;
}
    // Set up the buttons for the quiz
    //vector<string> choices = {"France", "Germany", "Italy", "Spain", "South Korea", "United States", "Canada", "Mexico", "Brazil", "Argentina", "Chile", "Colombia", "Peru", "Venezuela", "Ecuador", "Bolivia"};
    vector<string> choices= Plateau.getBoard();
    vector<SDL_Rect> buttonRects;
    for (int col = 0; col < NUM_COLS; col++) {
      for (int row = 0; row < NUM_ROWS; row++) {
        if (row==0 || row==NUM_ROWS-1 || col==0 || col==NUM_COLS-1){
            SDL_Rect rect;
            rect.x = col * WINDOW_WIDTH/5+10;
            rect.y = row * WINDOW_HEIGHT/5+35;
            rect.w = WINDOW_WIDTH/5;
            rect.h = WINDOW_HEIGHT/5;
            buttonRects.push_back(rect);
        }
      }
    }
    string diceText="Lancer le de";
    SDL_Surface* diceSurface = TTF_RenderText_Solid(font, diceText.c_str(), color);
    SDL_Texture* diceTexture = SDL_CreateTextureFromSurface(renderer, diceSurface);
    SDL_FreeSurface(diceSurface);
    SDL_Rect diceRect;
    diceRect.x=WINDOW_WIDTH/5+30;
    diceRect.y=WINDOW_HEIGHT/5+35;
    diceRect.w=diceSurface->w;
    diceRect.h=diceSurface->h;
  // Main game loop
  bool running = true;
  while (running) {
    // Process input
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }else if (event.type == SDL_MOUSEBUTTONDOWN) {
        int x = event.button.x;
        int y = event.button.y;
        if(turn==Turn::PLAYER_1){
          if(x>=diceRect.x && x<diceRect.x+diceRect.w && y >= diceRect.y && y < diceRect.y + diceRect.h){
            deplacement=rand()%3+1;
            joueur1.deplacement(deplacement,NUM_ROWS,NUM_COLS);
            joueur1.augmenter_indice(deplacement);
            cout<<"here "<<deplacement<<endl;
            lance_quiz(WINDOW_WIDTH,WINDOW_HEIGHT,joueur1,Plateau.getRandom()[joueur1.get_indice()],content);
            cout<<" "<<Plateau.getRandom()[joueur1.get_indice()]<<" "<<endl;
            cout<<joueur1 <<endl;;
            Mix_PlayChannel(-1, correctSound, 0);
            turn=Turn::PLAYER_2;
          }
        }else{
          if(x>=diceRect.x && x<diceRect.x+diceRect.w && y >= diceRect.y && y < diceRect.y + diceRect.h){
          deplacement=rand()%3+1;
          joueur2.deplacement(deplacement,NUM_ROWS,NUM_COLS);
          joueur2.augmenter_indice(deplacement);
          cout<<"here "<<deplacement<<endl;
          lance_quiz(WINDOW_WIDTH,WINDOW_HEIGHT,joueur2,Plateau.getRandom()[joueur2.get_indice()],content);
          cout<<" "<<Plateau.getRandom()[joueur2.get_indice()]<<" "<<endl;
          cout<<joueur2<<endl;
          Mix_PlayChannel(-1, correctSound, 0);
          turn=Turn::PLAYER_1;
          }
        }
      }
    }

    // Clear the renderer
    SDL_RenderClear(renderer);
    // Draw the image
  SDL_RenderCopy(renderer, texture, NULL, NULL);

  // Draw the pawn
  
    SDL_Rect pawnRect;
    pawnRect.x = joueur1.get_x()* WINDOW_WIDTH/5+100;
    pawnRect.y = joueur1.get_y()* WINDOW_HEIGHT/5+25;
    pawnRect.w = 50;
    pawnRect.h = 50;
    SDL_RenderCopy(renderer, pawnTexture, NULL, &pawnRect);
  
  // Draw the pawn
  
    SDL_Rect pawnRect2;
    pawnRect2.x = joueur2.get_x()* WINDOW_WIDTH/5+140;
    pawnRect2.y = joueur2.get_y() * WINDOW_HEIGHT/5+25;
    pawnRect2.w = 50;
    pawnRect2.h = 50;
    SDL_RenderCopy(renderer, pawnTexture, NULL, &pawnRect2);
  

     // Render the cells onto the board
    for (int row = 0; row < NUM_ROWS; row++) {
      for (int col = 0; col < NUM_COLS; col++) {
        if (row==0 || row==NUM_ROWS-1 || col==0 || col==NUM_COLS-1){
            SDL_Rect rect;
            rect.x = row * WINDOW_WIDTH/5;
            rect.y = col * WINDOW_HEIGHT/5;
            rect.w = WINDOW_WIDTH/5;
            rect.h = WINDOW_HEIGHT/5;

            // Set the color of the lines
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            // Draw the lines of the rectangle
            SDL_RenderDrawRect(renderer, &rect);
        }
      }
    }
    //Draw dice
    SDL_RenderCopy(renderer, diceTexture, nullptr, &diceRect);
    // Draw the buttons
    for (int i = 0; i < choices.size(); i++) {
        string buttonText = choices[convert_board(i)];
        SDL_Surface* buttonSurface = TTF_RenderText_Solid(font, buttonText.c_str(), color);
        SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);
        SDL_FreeSurface(buttonSurface);
        SDL_Rect buttonRect = buttonRects[i];
        buttonRect.w = buttonSurface->w;
        buttonRect.h = buttonSurface->h;
        SDL_RenderCopy(renderer, buttonTexture, nullptr, &buttonRect);
        SDL_DestroyTexture(buttonTexture);
    }
    //Draw the scores
    string scoreText = "Score "+joueur1.get_name()+": " + to_string(joueur1.get_score());
    SDL_Color color = {0, 0, 0, 0};
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), color);
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_FreeSurface(scoreSurface);
    SDL_Rect scoreRect;
    scoreRect.x = WINDOW_WIDTH/5+30;
    scoreRect.y = 2*WINDOW_HEIGHT/5+35;
    scoreRect.w = scoreSurface->w;
    scoreRect.h = scoreSurface->h;
    SDL_RenderCopy(renderer, scoreTexture, nullptr, &scoreRect);
    SDL_DestroyTexture(scoreTexture);

    //Draw the scores
    string scoreText2 = "Score "+joueur2.get_name()+": " + to_string(joueur2.get_score());
    SDL_Surface* scoreSurface2 = TTF_RenderText_Solid(font, scoreText2.c_str(), color);
    SDL_Texture* scoreTexture2 = SDL_CreateTextureFromSurface(renderer, scoreSurface2);
    SDL_FreeSurface(scoreSurface2);
    SDL_Rect scoreRect2;
    scoreRect2.x = WINDOW_WIDTH/5+30;
    scoreRect2.y = 2*WINDOW_HEIGHT/5+70;
    scoreRect2.w = scoreSurface2->w;
    scoreRect2.h = scoreSurface2->h;
    SDL_RenderCopy(renderer, scoreTexture2, nullptr, &scoreRect2);
    SDL_DestroyTexture(scoreTexture2);
    // Present the renderer to the window
    SDL_RenderPresent(renderer);
  }

  // Clean up
  Mix_FreeChunk(correctSound);
Mix_CloseAudio();
  SDL_DestroyTexture(diceTexture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}