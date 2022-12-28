#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
using namespace std;

int main()
{
    string fname="team_q.csv";
    
    vector<vector<string> > content;
    vector<string> row;
    string line, words,word;
 
    fstream file (fname, ios::in);
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
    }
    else
    cout<<"fichier pas ouvert \n";
 
    /*for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
            cout<<content[i][j]<<""<<endl;

        }
        cout<<"\n";


    }*/
    cout << content.size()<<" "<<content[0].size()<< " " <<content[1].size()<<endl;
    cout << content[34][2]<<endl;

    
 
    return 0;
}



