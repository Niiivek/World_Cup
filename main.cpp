#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "Box.hpp"
#include "Box_teams.hpp"
#include "Box_others.hpp"
#include "Pion.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
using namespace std;

// Screen dimensions
const int WINDOW_WIDTH = 700;
const int WINDOW_HEIGHT = 500;

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

/*

int main() {
    Boss_team Case1("chine","comment vas tu",10);
    Normal_team Case2("france","hi",5);
    Lucky_box Case3("Chance","Tu est qualifié à la phase suivante");
    vector <Box*> Board;
    Board.push_back(&Case1);
    Board.push_back(&Case2);
    Board.push_back(&Case3);
    Board[0]->affiche();
    Board[1]->affiche();
    Board[2]->affiche();

    Pion joueur1("mm");
    return 0;

}*/

void quizz(Box pays){

}
int main(int argc, char* argv[]) {
  /*vector <vector<string> > content=read_csv("team_q.csv");
  Boss_team Case1(content[1][0],content[1][2],content[1][3],content[1][4],content[1][5],content[1][3],5);
  Case1.affiche();*/
  // Initialize SDL2
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "Error initializing SDL2: " << SDL_GetError() << std::endl;
    return 1;
  }

  // Create the window
  SDL_Window* window = SDL_CreateWindow("Quiz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if (window == nullptr) {
    std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
    return 1;
  }

  // Create the renderer
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr) {
    std::cerr << "Error creating renderer: " << SDL_GetError() << std::endl;
    return 1;
  }
    // Initialize the TTF library
if (TTF_Init() != 0) {
  std::cerr << "Error initializing TTF: " << TTF_GetError() << std::endl;
  return 1;
}

// Load a font
TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
if (font == nullptr) {
  std::cerr << "Error loading font: " << TTF_GetError() << std::endl;
  return 1;
}

  // Load an image
  SDL_Surface* image = IMG_Load("image/white.jpg");
  if (image == nullptr) {
    std::cerr << "Error loading image: " << IMG_GetError() << std::endl;
    return 1;
  }

  // Create a texture from the image
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_FreeSurface(image);
  if (texture == nullptr) {
    std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
    return 1;
  }

 // Set up the quiz questions and answers
std::vector<std::string> questions = {"What is the capital of France?", "What is the currency of South Korea?"};
std::vector<std::string> answers = {"Paris", "Won"};
int currentQuestion = 0;
int score = 0;

// Set up the buttons for the quiz
std::vector<std::string> choices = {"Lyon", "Paris", "Bordeaux"};
std::vector<SDL_Rect> buttonRects;
for (int i = 0; i < choices.size(); i++) {
  SDL_Rect rect;
  rect.x = 50;
  rect.y = 100 + i * 50;
  rect.w = 100;
  rect.h = 20;
  buttonRects.push_back(rect);
}

// Set up the "SHOW_RESULT" state
std::string resultText;
SDL_Texture* resultTexture = nullptr;

// Set up the audio device
int audio_rate = 22050;
Uint16 audio_format = AUDIO_S16SYS;
int audio_channels = 2;
int audio_buffers = 4096;
if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
  std::cerr << "Error opening audio device: " << Mix_GetError() << std::endl;
  return 1;
}

// Load the sound effect for correct answers
Mix_Chunk* correctSound = Mix_LoadWAV("song/IHoqpnFWqJn_VEGEDREAM---RAMENEZ-LA-COUPE-A-LA-MAISON.mp3");

// Main loop
enum class State {
  SHOW_QUESTION,
  SHOW_RESULT
};

State state = State::SHOW_QUESTION;
bool running = true;
while (running) {
  // Process input
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      running = false;
    } else if (event.type == SDL_MOUSEBUTTONDOWN) {
      int x = event.button.x;
      int y = event.button.y;
      if (state == State::SHOW_QUESTION) {
        for (int i = 0; i < buttonRects.size(); i++) {
          if (x >= buttonRects[i].x && x < buttonRects[i].x + buttonRects[i].w && y >= buttonRects[i].y && y < buttonRects[i].y + buttonRects[i].h) {
            // Button i was clicked
            if (choices[i] == answers[currentQuestion]) {
              score++;
              resultText = "Correct!";
              Mix_PlayChannel(-1, correctSound, 0);
            } else {
              resultText = "Wrong!";
            }
            state = State::SHOW_RESULT;
            break;
          }
        }
      } else if (state == State::SHOW_RESULT) {
        // Stop the sound effect
        Mix_HaltChannel(-1);
        // Move on to the next question
        currentQuestion++;
        if (currentQuestion >= questions.size()) {
          // End of quiz
          running = false;
        } else {
            if(currentQuestion==1){
            choices = {"Euro", "Won", "Yen"};
            correctSound= Mix_LoadWAV("song/bts.mp3");
            } 
          state = State::SHOW_QUESTION;
        }
      }
    }
  }

  // Clear the screen
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);


  // Draw the image
  SDL_RenderCopy(renderer, texture, NULL, NULL);


  // Draw the score
  std::string scoreText = "Score: " + std::to_string(score);
  SDL_Color color = {0, 0, 0, 0}; // White
  SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), color);
  SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
  SDL_FreeSurface(scoreSurface);
  SDL_Rect scoreRect;
  scoreRect.x = 10;
  scoreRect.y = 10;
  scoreRect.w = scoreSurface->w;
  scoreRect.h = scoreSurface->h;
  SDL_RenderCopy(renderer, scoreTexture, nullptr, &scoreRect);
  SDL_DestroyTexture(scoreTexture);

if (state == State::SHOW_QUESTION) {
// Draw the question
    std::string questionText = questions[currentQuestion];
    SDL_Surface* questionSurface = TTF_RenderText_Solid(font, questionText.c_str(), color);
    SDL_Texture* questionTexture = SDL_CreateTextureFromSurface(renderer, questionSurface);
    SDL_FreeSurface(questionSurface);
    SDL_Rect questionRect;
    questionRect.x = 10;
    questionRect.y = 50;
    questionRect.w = questionSurface->w;
    questionRect.h = questionSurface->h;
    SDL_RenderCopy(renderer, questionTexture, nullptr, &questionRect);
    SDL_DestroyTexture(questionTexture);

    // Draw the buttons
    for (int i = 0; i < choices.size(); i++) {
        std::string buttonText = choices[i];
        SDL_Surface* buttonSurface = TTF_RenderText_Solid(font, buttonText.c_str(), color);
        SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);
        SDL_FreeSurface(buttonSurface);
        SDL_Rect buttonRect = buttonRects[i];
        buttonRect.w = buttonSurface->w;
        buttonRect.h = buttonSurface->h;
        SDL_RenderCopy(renderer, buttonTexture, nullptr, &buttonRect);
        SDL_DestroyTexture(buttonTexture);
    }
  } else if (state == State::SHOW_RESULT) {
    // Draw the result
    SDL_Surface* resultSurface = TTF_RenderText_Solid(font, resultText.c_str(), color);
    resultTexture = SDL_CreateTextureFromSurface(renderer, resultSurface);
    SDL_FreeSurface(resultSurface);
    SDL_Rect resultRect;
    resultRect.x = 10;
    resultRect.y = 50;
    resultRect.w = resultSurface->w;
    resultRect.h = resultSurface->h;
    SDL_RenderCopy(renderer, resultTexture, nullptr, &resultRect);
  }

  // Update the screen
  SDL_RenderPresent(renderer);
}

// Clean up
TTF_CloseFont(font);
Mix_FreeChunk(correctSound);
Mix_CloseAudio();
SDL_DestroyTexture(texture);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

return 0;
}