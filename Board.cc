#include "Headers/Board.hh"

Board::Board(string csv,int nb_cases){ // constructeur de notre plateau qui va créer des cases aléatoires à chaque fois
    content=read_csv(csv);
    //cout <<content.size()<<endl;
    tab=random(nb_cases,content.size()-1);
    for(int i=0;i<nb_cases;i++){
        board.push_back(content[tab[i]][0]);
    }lucky_indice=rand()%board.size();
}


vector<vector<string> > Board::read_csv(string csv){ // méthodes qui va lire notre csv pour obtenir les noms des pays, questions réponses
    vector<vector<string> > content;
    vector<string> row;
    string line, words,word;
 
    fstream file (csv, ios::in);
    if(file.is_open()){
        while(getline(file, line)){
            row.clear();
            stringstream str(line);
            while(getline(str, words, ',')){
                //cout<<words<<endl;
                for(int i=0;words[i]!='\0';i++){
                    if(words[i]!=';'){
                        word=word+words[i];
                    }else{
                        row.push_back(word);
                        word="";
                    }
                }row.push_back(word);
                word="";
                content.push_back(row);
            }
        }
    }else
        cout<<"fichier pas ouvert";
    return content;
}

vector <int> Board::random(int n,int max){ // méthode qui va créer un tableau d'entiers aléatoires
    vector <int> tab;
    int aleatoire=0;
    for(int i=0;i<n;i++){
        aleatoire=rand()%max+1;
        while(appartient(aleatoire,tab)==-1){
                aleatoire=rand()%max+1;
            }
        tab.push_back(aleatoire);
    }return tab;
}

int Board::appartient(int a,vector <int> tab ){ // méthode qui vérifie si un entier est dans notre tableau
    for(auto it:tab){
        if(it==a || it==0){
            return -1;
        }
    }return 0;
}

void Board::affiche_random(){// affichage du tableau random
    for(auto it:tab){
        cout<<it<<" ";
    }cout << endl;
}

vector <string> Board::getBoard(){
    return board;
}

vector <int> Board::getRandom(){
    return tab;
}

vector<vector<string>> Board::getContent(){
    return content;
}

int Board::getLucky_indice(){
    return lucky_indice;
}

ostream& operator<<(ostream& os, const Board& plateau){ // surchage d'opérateur permettant d'afficher les pays qu'on a dans notre plateau
    for(int i=0;i<plateau.board.size();i++){
        os << plateau.board[i]<< " ";
    }os <<endl;
    return os;
}