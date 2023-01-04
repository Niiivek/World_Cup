#include "Headers/Graphic.hpp"

Graphic::Graphic(int Width,int Height):window(NULL),renderer(NULL),font(NULL),image(NULL),texture(NULL),Window_Width(Width),Window_Height(Height){
}

Graphic::~Graphic(){
    TTF_CloseFont(font);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Graphic::Init(){
    // Initialize SDL2
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cerr << "Error initializing SDL2: " << SDL_GetError() << endl;
  }

  // Create the window
  window = SDL_CreateWindow("Quiz", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Window_Width, Window_Height, 0);
  if (window == nullptr) {
    cerr << "Error creating window: " << SDL_GetError() << endl;
    exit(EXIT_FAILURE);	
  }

  // Create the renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr) {
    cerr << "Error creating renderer: " << SDL_GetError() << endl;
    exit(EXIT_FAILURE);	
    }

  // Initialize the TTF library
  if (TTF_Init() != 0) {
    cerr << "Error initializing TTF: " << TTF_GetError() << endl;
    exit(EXIT_FAILURE);	
  }

  // Load a font
  font = TTF_OpenFont("arial.ttf", 24);
  if (font == nullptr) {
    cerr << "Error loading font: " << TTF_GetError() << endl;
    exit(EXIT_FAILURE);	
  }
}

void Graphic::load_image(){
    // Load an image
    image = IMG_Load("image/football.png");
    if (image == nullptr) {
        cerr << "Error loading image: " << IMG_GetError() << endl;
        exit(EXIT_FAILURE);	
    }

    // Create a texture from the image
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    if (texture == nullptr) {
        cerr << "Error creating texture: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);	
    }
}

void Graphic::Draw_question(){
    SDL_Color color = {0, 0, 0, 0};
    SDL_Surface* questionSurface = TTF_RenderText_Solid(font, question.c_str(), color);
    SDL_Texture* questionTexture = SDL_CreateTextureFromSurface(renderer, questionSurface);
    SDL_FreeSurface(questionSurface);
    SDL_Rect questionRect;
    questionRect.x = 50;
    questionRect.y = 50;
    questionRect.w = questionSurface->w;
    questionRect.h = questionSurface->h;
    SDL_RenderCopy(renderer, questionTexture, nullptr, &questionRect);
    SDL_DestroyTexture(questionTexture);
}

void Graphic::Draw_buttons(){
    SDL_Color color = {0, 0, 0, 0};
    for (int i = 0; i < choices.size(); i++) {
        string buttonText = choices[i];
        SDL_Surface* buttonSurface = TTF_RenderText_Solid(font, buttonText.c_str(), color);
        SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);
        SDL_FreeSurface(buttonSurface);
        SDL_Rect buttonRect = buttonRects[i];
        buttonRect.w = buttonSurface->w;
        buttonRect.h = buttonSurface->h;
        SDL_RenderCopy(renderer, buttonTexture, nullptr, &buttonRect);
        SDL_DestroyTexture(buttonTexture);
    }
}

void Graphic::Draw_result(string resultText,SDL_Texture* resultTexture){
    SDL_Color color = {0, 0, 0, 0};
    SDL_Surface* resultSurface = TTF_RenderText_Solid(font, resultText.c_str(), color);
    resultTexture = SDL_CreateTextureFromSurface(renderer, resultSurface);
    SDL_FreeSurface(resultSurface);
    SDL_Rect resultRect;
    resultRect.x = 50;
    resultRect.y = 50;
    resultRect.w = resultSurface->w;
    resultRect.h = resultSurface->h;
    SDL_RenderCopy(renderer, resultTexture, nullptr, &resultRect);
}

void Graphic::Draw_score(Pion joueur){
    string scoreText = "Score: " + to_string(joueur.get_score());
    SDL_Color color = {0, 0, 0, 0};
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), color);
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_FreeSurface(scoreSurface);
    SDL_Rect scoreRect;
    scoreRect.x = 50;
    scoreRect.y = 10;
    scoreRect.w = scoreSurface->w;
    scoreRect.h = scoreSurface->h;
    SDL_RenderCopy(renderer, scoreTexture, nullptr, &scoreRect);
    SDL_DestroyTexture(scoreTexture);
}

void Graphic::update_screen(){
    SDL_RenderPresent(renderer);
}

void Graphic::clean_screen(){
    SDL_SetRenderDrawColor(renderer, 0, 0,0, 255); 
	SDL_RenderClear(renderer);
}

void Graphic::init_quiz(Box_team pays){
    question=pays.getQ();
    answer=pays.getR();
    choices=pays.getChoices();
    for (int i = 0; i < choices.size(); i++) {
        SDL_Rect rect;
        rect.x = 50;
        rect.y = 100 + i * 50;
        rect.w = 100;
        rect.h = 20;
        buttonRects.push_back(rect);
    }
}

void Graphic::quiz_loop(Pion joueur,Box_team pays){
    string resultText;
    SDL_Texture* resultTexture = nullptr;
    State state = State::SHOW_QUESTION;
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running=false;
            }else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x;
                int y = event.button.y;
                if (state == State::SHOW_QUESTION) {
                    for (int i = 0; i < buttonRects.size(); i++) {
                        if (x >= buttonRects[i].x && x < buttonRects[i].x + buttonRects[i].w && y >= buttonRects[i].y && y < buttonRects[i].y + buttonRects[i].h) {
                        // Button i was clicked
                            if (pays.getChoices()[i] == pays.getR()) {
                                joueur.augmenter_score(1);
                                resultText = "Correct!";
                            }else{
                                resultText = "Wrong!";
                            }
                            state = State::SHOW_RESULT;
                            break;
                        }
                    }
                }else if (state == State::SHOW_RESULT) {
                    running=false;
                }
            }
        }
        clean_screen();
        // Draw the image
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        Draw_score(joueur);
        if (state == State::SHOW_QUESTION) {
            Draw_question();
            Draw_buttons();
        }else if (state == State::SHOW_RESULT) {
            Draw_result(resultText,resultTexture);
        }update_screen();
    }
}