#include "Headers/Graphic_Board.hpp"

Graphic_Board::Graphic_Board(int Width,int Height,int rows,int cols):window(NULL),renderer(NULL),font(NULL),image(NULL),texture(NULL),Window_Width(Width),Window_Height(Height),num_rows(rows),num_cols(cols){
    color = {0, 0, 0, 0};
}

Graphic_Board::~Graphic_Board(){
    Mix_FreeChunk(correctSound);
    Mix_CloseAudio();
    SDL_DestroyTexture(diceTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Graphic_Board::Init(){
    // Initialize SDL2
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cerr << "Error initializing SDL2: " << SDL_GetError() << endl;
  }

  // Create the window
  window = SDL_CreateWindow("World Cup Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Window_Width, Window_Height, 0);
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
  font = TTF_OpenFont("Sources/arial.ttf", 24);
  if (font == nullptr) {
    cerr << "Error loading font: " << TTF_GetError() << endl;
    exit(EXIT_FAILURE);	
  }

  // Set up the audio device
  int audio_rate = 22050;
  Uint16 audio_format = AUDIO_S16SYS;
  int audio_channels = 2;
  int audio_buffers = 4096;
  if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
    cerr << "Error opening audio device: " << Mix_GetError() << endl;
  }
  // Load the sound effect for correct answers
  correctSound = Mix_LoadWAV("Sources/IHoqpnFWqJn_VEGEDREAM---RAMENEZ-LA-COUPE-A-LA-MAISON.mp3");
}

void Graphic_Board::load_image(){
    // Load an image
    image = IMG_Load("image/football.png");
    if (image == nullptr) {
        cerr << "Error loading image: " << IMG_GetError() << endl;
    }

    // Create a texture from the image
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    if (texture == nullptr) {
        cerr << "Error creating texture: " << SDL_GetError() << endl;
    }
}

void Graphic_Board::load_pawn(){
    // Load the pawn image
    SDL_Surface* pawnImage = IMG_Load("image/pawn.png");
    if (pawnImage == nullptr) {
        cerr << "Error loading image: " << IMG_GetError() << endl;
    }
    // Create a texture from the pawn image
    pawnTexture = SDL_CreateTextureFromSurface(renderer, pawnImage);
    SDL_FreeSurface(pawnImage);
    if (pawnTexture == nullptr) {
        cerr << "Error creating texture: " << SDL_GetError() << endl;
  }
}

void Graphic_Board::init_de(){ // Initialise le texte pour le dé
    string diceText="Appuie pour lancer le de";
    SDL_Surface* diceSurface = TTF_RenderText_Solid(font, diceText.c_str(), color);
    diceTexture = SDL_CreateTextureFromSurface(renderer, diceSurface);
    SDL_FreeSurface(diceSurface);
    diceRect.x=Window_Width/5+30;
    diceRect.y=Window_Height/5+35;
    diceRect.w=diceSurface->w;
    diceRect.h=diceSurface->h;
}

void Graphic_Board::draw_pawn(Pion joueur,int x,int y){ // Ajoute l'image du pion
    SDL_Rect pawnRect;
    pawnRect.x = joueur.get_x()* Window_Width/5+x;
    pawnRect.y = joueur.get_y()* Window_Height/5+y;
    pawnRect.w = 50;
    pawnRect.h = 50;
    SDL_RenderCopy(renderer, pawnTexture, NULL, &pawnRect);
}

void Graphic_Board::init_plateau(){ // Initiliase les case du plateau de jeu
    for (int col = 0; col < num_cols; col++) {
      for (int row = 0; row < num_rows; row++) {
        if (row==0 || row==num_rows-1 || col==0 || col==num_cols-1){
            SDL_Rect rect;
            rect.x = row * Window_Width/5;
            rect.y = col * Window_Height/5;
            rect.w = Window_Width/5;
            rect.h = Window_Height/5;

            // Set the color of the lines
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            // Draw the lines of the rectangle
            SDL_RenderDrawRect(renderer, &rect);
        }
      }
    }
}

void Graphic_Board::init_case(){ // Initialise les rectangles des pays
    for (int col = 0; col < num_cols; col++) {
      for (int row = 0; row < num_rows; row++) {
        if (row==0 || row==num_rows-1 || col==0 || col==num_cols-1){
            SDL_Rect rect;
            rect.x = col * Window_Width/5+10;
            rect.y = row * Window_Height/5+35;
            rect.w = Window_Width/5;
            rect.h = Window_Height/5;
            buttonRects.push_back(rect);
        }
      }
    }
}

void Graphic_Board::draw_countries(Board Plateau,Lucky_box Chance){ // Ajoute les cases pays + case chance
    countries= Plateau.getBoard();
    SDL_Color color = {0, 0, 0, 0};
    for (int i = 0; i < countries.size(); i++) {
        string buttonText = countries[convert_board(i)];
        SDL_Surface* buttonSurface = TTF_RenderText_Solid(font, buttonText.c_str(), color);
        SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);
        SDL_FreeSurface(buttonSurface);
        SDL_Rect buttonRect = buttonRects[i];
        buttonRect.w = buttonSurface->w;
        buttonRect.h = buttonSurface->h;
        SDL_RenderCopy(renderer, buttonTexture, nullptr, &buttonRect);
        SDL_DestroyTexture(buttonTexture);
        if(convert_board(i)==Plateau.getLucky_indice()){
          string buttonText =Chance.getName();
          SDL_Surface* buttonSurface = TTF_RenderText_Solid(font, buttonText.c_str(), color);
          SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);
          SDL_FreeSurface(buttonSurface);
          SDL_Rect buttonRect;
          buttonRect.x=buttonRects[i].x;
          buttonRect.y=buttonRects[i].y+30;
          buttonRect.w = buttonSurface->w;
          buttonRect.h = buttonSurface->h;
          SDL_RenderCopy(renderer, buttonTexture, nullptr, &buttonRect);
          SDL_DestroyTexture(buttonTexture);
        }
    }
}

void Graphic_Board::draw_score(Pion joueur,int y){ // Ajoute les scores au milieu du plateau
    string scoreText = "Score "+joueur.get_name()+": " + to_string(joueur.get_score());
    SDL_Color color = {0, 0, 0, 0};
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), color);
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_FreeSurface(scoreSurface);
    SDL_Rect scoreRect;
    scoreRect.x = Window_Width/5+30;
    scoreRect.y = 2*Window_Height/5+y;
    scoreRect.w = scoreSurface->w;
    scoreRect.h = scoreSurface->h;
    SDL_RenderCopy(renderer, scoreTexture, nullptr, &scoreRect);
    SDL_DestroyTexture(scoreTexture);
}

void Graphic_Board::draw_victory(string winner){ // Affiche le joueur qui a gagné
    string WinnerText =winner+" a gagne la partie !!!!!!!";
    SDL_Surface* WinnerSurface = TTF_RenderText_Solid(font, WinnerText.c_str(), color);
    SDL_Texture* WinnerTexture = SDL_CreateTextureFromSurface(renderer, WinnerSurface);
    SDL_FreeSurface(WinnerSurface);
    SDL_Rect WinnerRect;
    WinnerRect.x = Window_Width/10;
    WinnerRect.y = Window_Height/10;
    WinnerRect.w = WinnerSurface->w+400;
    WinnerRect.h = WinnerSurface->h;
    SDL_RenderCopy(renderer, WinnerTexture, nullptr, &WinnerRect);
    SDL_DestroyTexture(WinnerTexture);
}

void Graphic_Board::update_screen(){
    SDL_RenderPresent(renderer);
}

void Graphic_Board::clean_screen(){
    SDL_SetRenderDrawColor(renderer, 0, 0,0, 255); 
	SDL_RenderClear(renderer);
}

void Graphic_Board::lance_quiz(Pion& joueur,int pays,vector <vector<string>> content){
    if(content[pays][1]=="Boss"){
        Boss_team Case1(content[pays][0],content[pays][2],content[pays][3],content[pays][4],content[pays][5],content[pays][6]);
        Graphic_Quizz test(Window_Width,Window_Height);
        test.Init();
        test.load_image();
        test.init_quiz(Case1);
        test.quiz_loop(joueur,Case1);
    }else{
        Normal_team Case1(content[pays][0],content[pays][2],content[pays][3],content[pays][4],content[pays][5],content[pays][6]);
        Graphic_Quizz test(Window_Width,Window_Height);
        test.Init();
        test.load_image();
        test.init_quiz(Case1);
        test.quiz_loop(joueur,Case1);
    }
}

void Graphic_Board::game_loop(Board Plateau,Pion & joueur1,Pion & joueur2){
    int deplacement=0;
    string winner;
    Lucky_box Chance;
    Turn turn=Turn::PLAYER_1;
    init_de();
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x = event.button.x;
                int y = event.button.y;
                if((joueur1.get_score()>=10 || joueur2.get_score()>=10) && turn!=Turn::VICTORY){
                    if(joueur1.get_score()>=2){
                        winner=joueur1.get_name();
                    }else{
                        winner=joueur2.get_name();
                    }
                    Mix_PlayChannel(-1, correctSound, 0);
                    image = IMG_Load("image/france.jpeg");
                    texture = SDL_CreateTextureFromSurface(renderer, image);
                    turn=Turn::VICTORY;
                }else{
                    if(turn==Turn::PLAYER_1){
                        if(x>=diceRect.x && x<diceRect.x+diceRect.w && y >= diceRect.y && y < diceRect.y + diceRect.h){
                            deplacement=rand()%5+1;
                            cout<<"Tour du "+ joueur1.get_name()<<endl;
                            cout<<"Le dé est tombé sur "+ to_string(deplacement)<<endl;
                            joueur1.deplacement(deplacement,num_rows,num_cols);
                            joueur1.augmenter_indice(deplacement,15);
                            if(joueur1.get_indice()==Plateau.getLucky_indice()){
                                Chance.affiche();
                                joueur1.augmenter_score(Chance.getEffet());
                            }lance_quiz(joueur1,Plateau.getRandom()[joueur1.get_indice()],Plateau.getContent());
                            turn=Turn::PLAYER_2;
                        }
                    }else if(turn==Turn::PLAYER_2){
                        if(x>=diceRect.x && x<diceRect.x+diceRect.w && y >= diceRect.y && y < diceRect.y + diceRect.h){
                            deplacement=rand()%5+1;
                            cout<<"Tour du"+ joueur2.get_name()<<endl;
                            cout<<"Le dé est tombé sur "+ to_string(deplacement)<<endl;
                            joueur2.deplacement(deplacement,num_rows,num_cols);
                            joueur2.augmenter_indice(deplacement,15);
                            if(joueur2.get_indice()==Plateau.getLucky_indice()){
                                Chance.affiche();
                                joueur2.augmenter_score(Chance.getEffet());
                            }lance_quiz(joueur2,Plateau.getRandom()[joueur2.get_indice()],Plateau.getContent());
                            turn=Turn::PLAYER_1;
                        }
                    }
                }
            }
        }clean_screen();
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        if(turn!=Turn::VICTORY){
            SDL_RenderCopy(renderer, diceTexture, nullptr, &diceRect);
            draw_pawn(joueur1,100,25);
            draw_pawn(joueur2,140,25);
            init_plateau();
            init_case();
            draw_countries(Plateau,Chance);
            draw_score(joueur1,35);
            draw_score(joueur2,70);
        }else{
            draw_victory(winner);
        }update_screen();
    }
}