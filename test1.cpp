#include <bits/stdc++.h>
#include <Windows.h> 
#include <WinCon.h>
#include <conio.h>
#include <thread>

#define MAX_WIDTH 110
#define MAX_HEIGTH 26
#define position SetConsoleCursorPosition
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESCAPE 27


using namespace std;


const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
bool feelEdges(COORD *p);

void updateLocation(COORD *p, pair<int, int> update);



int main()
{
    //Load map
    for (int i=0; i<MAX_HEIGTH ; i++)
    {
        for(int j=0; j<MAX_WIDTH; j++)
        {
        COORD pos = {(SHORT) (5+j), (SHORT) (2+i)};
        position(hConsole, pos);
        if(i==0 || j==0 || i == MAX_HEIGTH-1 || j==MAX_WIDTH-1)
        {SetConsoleTextAttribute(hConsole, 0x10);}
        else{SetConsoleTextAttribute(hConsole, 0x20);}
        cout << " ";
        }
    }


    //load character
    COORD *point=(COORD *)malloc(sizeof(COORD));
    *point= {9, 5};

    position(hConsole, *point);
    SetConsoleTextAttribute(hConsole, 0x40);
    cout << "  ";


    while(1) 
    {
        switch (getch())
        {
        case KEY_ESCAPE: //exit method by using escape key
            free(point);
            exit(1);
            break;
        
        case KEY_UP:
        updateLocation(point, pair<int, int> (0, -1));
        Sleep(50);

            break;

        case KEY_DOWN:
        updateLocation(point, pair<int, int> (0, 1));
        Sleep(50);
            break;
        
        case KEY_RIGHT:
        updateLocation(point, pair<int, int> (1, 0));
            break;
        
        case KEY_LEFT:
        updateLocation(point, pair<int, int> (-1, 0));
            break;

        
        
        }
    }

    return 0;

}


void updateLocation(COORD *p, pair<int, int> update)
{ 
    position(hConsole, *p);
    SetConsoleTextAttribute(hConsole, 0x20);
    cout << "  ";
    COORD temp ={SHORT(p->X+update.first), SHORT(p->Y + update.second)};
    if(!feelEdges(&temp))
    {
    p->X= p->X + update.first;
    p->Y= p->Y + update.second;

    }

    position(hConsole, *p);
    SetConsoleTextAttribute(hConsole, 0x40);
    cout << "  ";
    delete(&temp);
    return;
}


bool feelEdges(COORD *p)
{
    if (p->X==5 || p->X+1==MAX_WIDTH+4 || p->Y==2 || p->Y==MAX_HEIGTH+1)
    {
        return true;
    }
    return false;
}
