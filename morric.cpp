#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;


#define HEIGHTSTR 2
#define WIDTHSTR 5

typedef struct player
{
    string name = "";
    int tokenNum =9;
    pair <bool, pair <int, char>>fichas[9];
    
}player;


pair<int, int> Convertion (string in);
bool sameLocation(pair<int, char> pos);
bool validLocation(pair <int, char> pos);
void displayBoard ();
bool foundNearPos (string in1, string in2);

HANDLE hconsole =GetStdHandle(STD_OUTPUT_HANDLE);



map <int, vector<char>> validPos={{1, {'A', 'D', 'G'}},
                            {2, {'B', 'D', 'F'}},
                            {3, {'C', 'D', 'E'}},
                            {4, {'A','B', 'C', 'E', 'F', 'G'}},
                            {5, {'C', 'D', 'E'}},
                            {6, {'B', 'D', 'F'}},
                            {7, {'A', 'D', 'G', }}};




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

    cout<< "     __  ___                _                                   " << endl;   
    cout<< "    /  |/  /___  __________(_)____   ____ _____ _____ ___  ___  " << endl;  
    cout<< "   / /|_/ / __  / ___/ ___/ / ___/  / __ `/ __ `/ __ `__  / _   " << endl;  
    cout<< "  / /  / / /_/ / /  / /  / (__  )  / /_/ / /_/ / / / / / /  __/ " << endl;  
    cout<< " /_/  /_/ ____/_/  /_/  /_/____/    __, / __,_/_/ /_/ /_/ ___/  " << endl;  
    cout<< "                                  /____/                        " << endl << endl; 

    cout << "Ingrese nombre de jugador 1 (blancas): \n";
    cin >> temp;
    PLAYER[0]->name=temp;

    cin.ignore(40, '\n');

    cout << "Ingrese nombre de jugador 2 (negras): \n";
    cin >> temp;
    PLAYER[1]->name=temp;

    //start phase 1

    for(int i=0; i<18; i++)
    {
        string in;
        pair<int,int> pos={1,1}; //random start value

        displayBoard(); 
        cout << "Fase de colocar fichas" <<endl;

        do{

            if(pos.first==0 && pos.second==0) cout << "Uso correcto: 1A" << endl;

            cout << "Player " << (i%2)+1 << ": Introduzca posicion de ficha(ejem 1A): ";
            cin >> in;
            cin.ignore(123, '\n');

            //check input's validity 
            pos =Convertion(in);
            if(board [pos.second][pos.first]!='*') pos= {0,0};
            
        }
        while(pos.first==0 && pos.second == 0);

        board[pos.second][pos.first]=(i%2==0 ? 'w':'b');

    
        

    }

    //phase 2
    int i=0;

    while(PLAYER[0]->tokenNum <3 || PLAYER[1]->tokenNum <3 )
    {

        pair<int, int> pos1 ={1,1}; //random star value
        pair<int, int> pos2;
        string in1, in2;
        bool back=false;
     

        displayBoard();

        cout << "Fase mover fichas" <<endl;

        do{


        do{

            if(pos1.first==0 && pos1.second==0) cout << "Uso correcto: 1A" << endl;

            cout << "Player " << (i%2)+1 << ": Introduzca posicion de ficha(ejem 1A): ";
            cin >> in1;
            cin.ignore(123, '\n');

            //check input's validity 
            pos1 =Convertion(in1);
            if(i%2==0) {if(board [pos1.second][pos1.first]!='w') pos1= {0,0};}
            else{if(board [pos1.second][pos1.first]!='b') pos1= {0,0};}
            
        }
        while(pos1.first==0 && pos1.second == 0);

        do{
        back=false;
        cout << "Ingrese nueva posicion o ingrese ''Atras'' para selecionar otra ficha  : ";
        cin >> in2;
        cin.ignore(123, '\n');
        if(strcmp(in2.c_str(), "Atras")==0) 
            {back=true;
            break;}
        pos2= Convertion(in2);
        if(board[pos2.second][pos2.first]!='*') pos2={0,0};
        }while(pos2.first==0 && pos2.second == 0);

        }while(back || foundNearPos(in1, in2));

        



        i++;
    }






    



    getch();
    free(PLAYER[0]);
    free(PLAYER[1]);
}

bool validLocation(pair <int, char> pos)
{
    for (auto e: validPos)
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
/*
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
*/


pair <int, int> Convertion (string in)
{
    if(strcmp(in.c_str(), "1A")==0) return {3,1};
    else if(strcmp(in.c_str(), "1D")==0) return {3,7};
    else if(strcmp(in.c_str(), "1G")==0) return {3,13};
    else if(strcmp(in.c_str(), "2B")==0) return {7,3};
    else if(strcmp(in.c_str(), "2D")==0) return {7,7};
    else if(strcmp(in.c_str(), "2F")==0) return {7,11};
    else if(strcmp(in.c_str(), "3C")==0) return {11,5};
    else if(strcmp(in.c_str(), "3D")==0) return {11,7};
    else if(strcmp(in.c_str(), "3E")==0) return {11,9};
    else if(strcmp(in.c_str(), "4A")==0) return {15,1};
    else if(strcmp(in.c_str(), "4B")==0) return {15,3};
    else if(strcmp(in.c_str(), "4C")==0) return {15,5};
    else if(strcmp(in.c_str(), "4E")==0) return {15,9};
    else if(strcmp(in.c_str(), "4F")==0) return {15,11};
    else if(strcmp(in.c_str(), "4G")==0) return {15,13};
    else if(strcmp(in.c_str(), "5C")==0) return {19,5};
    else if(strcmp(in.c_str(), "5D")==0) return {19,7};
    else if(strcmp(in.c_str(), "5E")==0) return {19,9};
    else if(strcmp(in.c_str(), "6B")==0) return {23,3};
    else if(strcmp(in.c_str(), "6D")==0) return {23,7};
    else if(strcmp(in.c_str(), "6F")==0) return {23,11};
    else if(strcmp(in.c_str(), "7A")==0) return {27,1};
    else if(strcmp(in.c_str(), "7D")==0) return {27,7};
    else if(strcmp(in.c_str(), "7G")==0) return {27,13};
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
        cout << endl << endl;
    }

}

bool foundNearPos (string in1, string in2)
{
    for(int i=1; in1[1]-i>='A'; i++) //go up
    {
        pair <int, char> temp= {in1[0]-'0', in1[1]-i};
        if(validLocation(temp))
        {
            if(temp== (pair<int, char>){in2[0]-'0', in2[1]}) return true;

            break;
        }
    }

    for(int i=1; in1[1]+i<='G'; i++) //go down
    {
        pair <int, char> temp= {in1[0]-'0', in1[1]+i};
        if(validLocation(temp))
        {
            if(temp== (pair<int, char>){in2[0]-'0', in2[1]}) return true;

            break;
        }
    }

    for(int i=1; in1[0]-i>='1'; i++) //go left
    {
        pair <int, char> temp= {in1[0]-'0'-i, in1[1]};
        if(validLocation(temp))
        {
            if(temp== (pair<int, char>){in2[0]-'0', in2[1]}) return true;

            break;
        }
    }

    for(int i=1; in1[0]+i<='7'; i++) //go right
    {
        pair <int, char> temp= {in1[0]-'0'+i, in1[1]};
        if(validLocation(temp))
        {
            if(temp== (pair<int, char>){in2[0]-'0', in2[1]}) return true;

            break;
        }
    }


    return false;
}







