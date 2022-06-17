#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

typedef struct player
{
    string name = "";
    pair <bool, pair <int, char>>fichas[9];
    
}player;

bool sameLocation(pair<int, char> pos);
bool uselessLocation(pair <int, char> pos);

HANDLE hconsole =GetStdHandle(STD_OUTPUT_HANDLE);

map <int, vector<char>> M={{1, {'B', 'C', 'E', 'F'}},
                            {2, {'A', 'C', 'E', 'G'}},
                            {3, {'A', 'B', 'F', 'G'}},
                            {4, {'D'}},
                            {5, {'A', 'B', 'F', 'G'}},
                            {6, {'A', 'C', 'E', 'G'}},
                            {7, {'B', 'C', 'E', 'F'}}};



player *PLAYER[2];

int main()
{
    //inicitialize variables and get data from players
    PLAYER[0]= (player*) calloc(1, sizeof(player));
    PLAYER[1]= (player*) calloc(1, sizeof(player));

    string temp;
    cout << PLAYER[0]->fichas->first << " " << PLAYER[0]->fichas->second.first << endl;

    cout << "Ingrese nombre de jugador 1 (blancas): \n";
    cin >> temp;
    PLAYER[0]->name=temp;

    cin.ignore(40, '\n');

    cout << "Ingrese nombre de jugador 2 (negras): \n";
    cin >> temp;
    PLAYER[1]->name=temp;

    //display board

    char board [][29]= {{"   1   2   3   4   5   6   7"},
                        {"A  * - - - - - * - - - - - *"},
                        {"   |           |           |"},
                        {"B  |   * - - - * - - - *   |"},
                        {"   |   |       |       |   |"},
                        {"C  |   |   * - * - *   |   |"},
                        {"   |   |   |       |   |   |"},
                        {"D  * - * - *       * - * - *"},
                        {"   |   |   |       |   |   |"},
                        {"E  |   |   * - * - *   |   |"},
                        {"   |   |       |       |   |"},
                        {"F  |   * - - - * - - - *   |"},
                        {"   |           |           |"},
                        {"G  *-----------*-----------*"}
    };


    for(int i=0; i<14; i++)
    {
        for(int j=0; j<29; j++)
        {
            cout << board [i][j];
        }
        cout << endl;
    }

    //start phase 1
    for(int i=0; i<18; i++)
    {
        cout << "Player " << (i%2)+1 << ": Introduzca posicion de ficha(ejem 1A): ";

        string in;

        bool goodInput= false;

        do{
        cin >> in;
        //check input's validity 
        while((int)in.size()!= 2 || !isdigit(in[0]) || !isalpha(in[1]))
        {
            cout << "Uso correcto (ejemplo): 1A" << endl;
            cout << "Player " << (i%2)+1 << ": Introduzca posicion de ficha(ejem 1A): ";
            cin >> in;
        }


        pair<int, char> pos;
        
        pos.first= in[0]-'0';

        pos.second= in[1];

        if(!uselessLocation(pos))
        {
            if(!sameLocation(pos)) goodInput=true;
        }
        
        }while(!goodInput);

        //end of input validation


        

        

    }






    



    getch();
    free(PLAYER[0]);
    free(PLAYER[1]);
}

bool uselessLocation(pair <int, char> pos)  //check if the pos is a useless location
{
    for (auto e: M)
    {
        if(e.first==pos.first)
        {
            for(int i=0; i<(int) e.second.size(); i++)
            {
                if(e.second[i]==pos.second) return true;
            }
        }
    }
    return false;

}
bool sameLocation(pair<int, char> pos){ //check if there is one more token with the same location

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(PLAYER[i]->fichas[j].first && PLAYER[i]->fichas[j].second.first==pos.first && PLAYER[i]->fichas[j].second.second == pos.second) return true;
        }
    }

    return false;
}

