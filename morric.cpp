#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;


#define HEIGHTSTR 2
#define WIDTHSTR 5

typedef struct player
{
    string name = "";
    pair <bool, pair <int, char>>fichas[9];
    
}player;

pair<int, int> Convertion (string in);
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



    for(int i=0; i<14; i++)
    {
        for(int j=0; j<29; j++)
        {

            COORD pos= {(SHORT) (WIDTHSTR+ j),(SHORT) (HEIGHTSTR+i)};
            SetConsoleCursorPosition(hconsole, pos);
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
        pair<int,int> pos;

        do{
        cin >> in;
        //check input's validity 
        while((int)in.size()!= 2 || !isdigit(in[0]) || !isalpha(in[1]))
        {
            cout << "Uso correcto (ejemplo): 1A" << endl;
            cout << "Player " << (i%2)+1 << ": Introduzca posicion de ficha(ejem 1A): ";
            cin >> in;
        }

        pos =Convertion(in);
        }
        while(pos.first==0 && pos.second == 0);




        /*pair<int, char> pos;
        
        pos.first= in[0]-'0';
        pos.second= in[1];
        if(!uselessLocation(pos))
        {
            if(!sameLocation(pos)) goodInput=true;
        }
        
        }while(!goodInput);
        //end of input validation*/
        







        

        

    }






    



    getch();
    free(PLAYER[0]);
    free(PLAYER[1]);
}

bool uselessLocation(pair <int, char> pos)
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
bool sameLocation(pair<int, char> pos){

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(PLAYER[i]->fichas[j].second.first==pos.first && PLAYER[i]->fichas[j].second.second == pos.second) return true;
        }
    }

    return false;
}


pair <int, int> Convertion (string in)
{
    if(strcmp(in.c_str(), "1A")) return {3,2};
    else if(strcmp(in.c_str(), "1D")) return {3,9};
    else if(strcmp(in.c_str(), "1G")) return {3,15};
    else if(strcmp(in.c_str(), "2B")) return {7,5};
    else if(strcmp(in.c_str(), "2D")) return {7,9};
    else if(strcmp(in.c_str(), "2F")) return {7,13};
    else if(strcmp(in.c_str(), "3C")) return {11,7};
    else if(strcmp(in.c_str(), "3D")) return {11,9};
    else if(strcmp(in.c_str(), "3E")) return {11,11};
    else if(strcmp(in.c_str(), "4A")) return {15,3};
    else if(strcmp(in.c_str(), "4B")) return {15,5};
    else if(strcmp(in.c_str(), "4C")) return {15,7};
    else if(strcmp(in.c_str(), "4E")) return {15,11};
    else if(strcmp(in.c_str(), "4F")) return {15,13};
    else if(strcmp(in.c_str(), "4G")) return {15,15};
    else if(strcmp(in.c_str(), "5C")) return {19,7};
    else if(strcmp(in.c_str(), "5D")) return {19,9};
    else if(strcmp(in.c_str(), "5E")) return {19,11};
    else if(strcmp(in.c_str(), "2B")) return {23,5};
    else if(strcmp(in.c_str(), "2D")) return {23,9};
    else if(strcmp(in.c_str(), "2F")) return {23,13};
    else if(strcmp(in.c_str(), "1A")) return {27,2};
    else if(strcmp(in.c_str(), "1D")) return {27,9};
    else if(strcmp(in.c_str(), "1G")) return {27,15};
    else return {0,0};
}


void displayBoard ()
{
    system("cls");

    for(int i=0; i<14; i++)
    {
        for(int j=0; j<29; j++)
        {

            COORD pos= {(SHORT) (WIDTHSTR+ j),(SHORT) (HEIGHTSTR+i)};
            SetConsoleCursorPosition(hconsole, pos);
            cout << board [i][j];
        }
        cout << endl;
    }

}
