#include <iostream>
#include <cmath>
#include <string>
#include <array>
#include <conio.h>
#include <fstream>

using namespace std;

void PlayGame();
void Menu();
void Intruduction();
void HowToPlay();
void Credits();
void print(string Arr[14][14]);

void Move(string (&arr)[14][14] , string player);
int winCheckXO( string Arr[14][14] , string player );
int WinChecker (string Arr[14][14]);
void MoveBlock(string (&arr)[14][14] , string player);

typedef string (&string2d)[6][6];
string2d  copyString(string Arr[14][14]);

typedef string (&string3dar3)[3][3];
string3dar3 convertTo3(string2d f1 , int block);
void antiClockWise(string (&mat)[3][3]);
void clockWise(string (&mat)[3][3]);
void putBackto14(string3dar3 f2 , string (arr)[14][14] , int block);
void rotate(string (&str)[14][14] , int block , char side) ;

void MoveMenu( char &option);
void print133(string Arr[13][3]);

struct data{
    string name;
    int win;
    int lost;
    int draw;
};

void sortRanking();
void addToFile(string name , int w);
void print_ranking();


int main()
{
    char menu_select;
    char b;
    cout << "Hello and welcome to the Pentago game!"<< endl;

    cout << endl <<"press any button to Start!"<<endl;
    do{
         menu_select = getch();
         system("cls");
         MoveMenu(menu_select);
        switch(menu_select)
        {
            case '1':
                      PlayGame();
                      cout << endl << "press any button to enter menu"<<endl;
                      b=getch();
                      system("cls");
                      Menu();
                      break;
            case '2':
                      Intruduction();
                      cout << endl << "press any button to enter menu"<<endl;
                      b=getch();
                      system("cls");
                      Menu();
                      break;
            case '3':
                      HowToPlay();
                      cout << endl << "press any button to enter menu"<<endl;
                      b=getch();
                      system("cls");
                      Menu();
                      break;
            case '4':
                      Credits();
                      cout << endl << "press any button to enter menu"<<endl;
                      b=getch();
                      system("cls");
                      Menu();
                      break;
            case '5':
                      print_ranking();
                      cout << endl << "press any button to enter menu"<<endl;
                      b=getch();
                      system("cls");
                      Menu();
                      break;
            case '6':
                      cout << "Are you sure you want to quit?(y/n)" << endl;
                      b=getch();
                      if(b == 'y') return 0;
                      else if (b == 'n') {system("cls"); Menu();}
                      break;
            default :
                      system("cls");
                      cout << "Invalid Input!\n";
                      cout << endl << "press any button to enter menu"<<endl;
                      b=getch();
                      system("cls");
                      Menu();
                      break;
        }
    } while (true);

}

void Menu()
{
    string Arr[13][3] = {{"\u250c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2510"},
                         {"\u2502","       Play  Game       ","\u2502"},
                         {"\u251c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2524"},
                         {"\u2502","Instructions to the game","\u2502"},
                         {"\u251c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2524"},
                         {"\u2502","       How to play      ","\u2502"},
                         {"\u251c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2524"},
                         {"\u2502","         credits        ","\u2502"},
                         {"\u251c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2524"},
                         {"\u2502","         Ranking        ","\u2502"},
                         {"\u251c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2524"},
                         {"\u2502","          Quit          ","\u2502"},
                         {"\u2514","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2518"}
                        };
    print133(Arr);
}

void HowToPlay()
{
    system("cls");
        string Arr[14][14] = {{"\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510","\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518","\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518"},
                          {"\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510","\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518","\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518"}};
    cout << "How to play :\n";
    print(Arr);
        cout << "at the beginning of the game you should enter the player names. \n"
             <<"Notice!: player 1 plays with X and player 2 plays with O. \n"
             <<"There is the ability to re-enter the player names after entering the names but after starting the game you can not change theme.\n"
             <<"\nAs you enter the game each player should fill a house with X/O and rotate one of the blocks.\n"
             <<"You can move through the houses and blocks using \"A/S/W/D\" keys on the keyboard.\n"
             <<"To enter your character use the \"ENTER\" button and to rotate the blocks use the \"R\" button to rotate right and the \"L\" button to rotate left.\n"
             <<endl;
        cout << "\nHope you enjoy."
             <<endl;
}

void Intruduction()
{
     system("cls");
     string Arr[14][14] = {{"\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510","\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518","\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518"},
                          {"\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510","\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518","\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518"}};
        cout << "Instructions to the game :\n"
             << "The game is played on a 6*6 board divided into four 3*3 sub-boards (or quadrants). \n"
             << "Taking turns, the two players place a marble of their color (either black or white) onto an unoccupied space on the board, and then rotate one of the sub-boards by 90 degrees either clockwise or anti-clockwise. \n"
             << "A player wins by getting five of their marbles in a vertical, horizontal or diagonal row and if non of these happen , its a draw.\n"
             << endl;
     print(Arr);


}

void Credits()
{
        system("cls");
        cout << "This game is developed by \"Mohammad H. Langarizadeh\" & \"Mohammad R. Khani\"\nShahid Beheshti University \n"
             << "\nHope you enjoy ...\n";
}

void PlayGame()
{
    system("cls");

    string Arr[14][14] = {{"\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510","\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518","\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518"},

                          {"\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510","\u250c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u252c","\u2500\u2500\u2500","\u2510"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524","\u251c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u253c","\u2500\u2500\u2500","\u2524"},
                          {"\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502","\u2502 "," "," \u2502 "," "," \u2502 "," "," \u2502 "},
                          {"\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518","\u2514","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2534","\u2500\u2500\u2500","\u2518"}
                          };

    string Player1;
    string Player2;
    char a = 48;
        do{
            cout << "Enter the name of player-1 :: \n"; cin>>Player1;
            system("cls");
            cout << "Enter the name of player-2 :: \n"; cin>>Player2;
            system("cls");
            cout << "Players are " << Player1 << " as player No.1 and " << Player2 << " as player No.2.\n\n";
            cout << "Press any button to confirm and 0 to get names again."<<endl;
            a = getch();
            system("cls");
        } while (a == 48);

    int Turn = 1;
    string chplayer;
    string Nameplayer;
    int Q = WinChecker(Arr);
    int counter = 0 ;
        while (Q == 0)
            {
                counter++;
                if (Turn == 1){chplayer = "x"; Nameplayer = Player1;}
                if (Turn == 2) {chplayer = "o"; Nameplayer = Player2;}

                cout << Nameplayer << " move as " << chplayer << " :" << endl;
                Move(Arr , chplayer);
                system("cls");
                cout << Nameplayer << " Please rotate a block to right (press R) or left (Press L) using keyboard buttons:" << endl;
                MoveBlock(Arr , chplayer);
                system("cls");
                Q = WinChecker(Arr);

                if (Turn == 1) {Turn = 2;}
                else if (Turn == 2) {Turn = 1;}
            }

        if (Q == 1)
            {cout << Player1 << " you won!" << endl;
            print(Arr);
            addToFile(Player1 , 1);
            addToFile(Player2 , 0); }
        else if (Q == 2)
            {cout << Player2 << " you won!" << endl;
            print(Arr);
            addToFile(Player2 , 1);
            addToFile(Player1 , 0);}
        else if (Q == 3)
            {cout << "Draw!" << endl;
            print(Arr);
            addToFile(Player1 , 2);
            addToFile(Player2 , 2);}

        else if (counter == 36)                 //if they did 36 playes and no one won!
            {cout << "Draw!" << endl;
            print(Arr);
            addToFile(Player1 , 2);
            addToFile(Player2 , 2);}

        sortRanking();
}

void print(string Arr[14][14])
{
    for(int i = 0 ; i < 14 ; i++){
        for (int j = 0 ; j < 14 ; j++)
                cout << Arr[i][j];
                cout <<endl;}
}

void print133(string Arr[13][3])
{
    for(int i = 0 ; i < 13 ; i++){
        for (int j = 0 ; j < 3 ; j++)
                cout << Arr[i][j];
                cout <<endl;}
}

string2d  copyString(string Arr[14][14])
{
        static string tempArr[6][6];
        int p , q;                  // shomarande arr[6][6]

    p=0;                             //block 1
        for(int i=1 ; i<=5 ; i+=2)
        {
            q=0;
            for(int j=1 ; j<=5 ; j+=2)
                {
                    tempArr[p][q] = Arr[i][j];
                    q++;
                }
            p++;
        }
    p=0;                              //block 2
        for(int i=1 ; i<=5 ; i+=2)
        {
            q=3;
            for(int j=8 ; j<=12 ; j+=2)
                {
                    tempArr[p][q] = Arr[i][j];
                    q++;
                }
            p++;
        }

    p=3;                                //block 3
        for(int i=8 ; i<=12 ; i+=2)
        {
            q = 0;
                for(int j=1 ; j<=5 ; j+=2)
                    {
                        tempArr[p][q] = Arr[i][j];
                        q++;
                    }
            p++;
        }

    p=3;                                    //block 4
        for(int i = 8 ; i<=12 ; i+=2)
        {
            q=3;
            for(int j = 8 ; j<=12 ; j+=2)
                {
                    tempArr[p][q] = Arr[i][j];
                    q++;
                }
            p++;
        }

    return tempArr;
}

void Move(string (&arr)[14][14] , string player)
{
    int satr = 1 , soton = 1;
    string temp[14][14];                          //To keep Arr[14][14] safe and play with a copy!
    for(int p1=0 ; p1<14 ; p1++)
        for(int p2=0 ; p2<14 ; p2++)
            temp[p1][p2]=arr[p1][p2];
            // The very first double-line on the char!::
         temp[satr-1][soton] = "\u2550\u2550\u2550";
         temp[satr+1][soton] = "\u2550\u2550\u2550";
         temp[satr][soton-1] = "\u2551 "  ;
         temp[satr][soton+1] = " \u2551 "  ;
         temp[satr-1][soton-1] = "\u2554";
         temp[satr+1][soton+1] = "\u255d";
         temp[satr-1][soton+1] = "\u2557";
         temp[satr+1][soton-1] = "\u255a";

    print(temp);

    while(1) //Just do it under no sercanstances!!
    {
        string temp[14][14];                         //To reverse the graphic modofication every time!
             for(int p1=0 ; p1<14 ; p1++)
                 for(int p2=0 ; p2<14 ; p2++)
                         temp[p1][p2]=arr[p1][p2];

        char action = getch() ;         //so what do you want to do with a house ??
        system("cls");
        if(action=='w' )
        {
            if ( satr == 1 ){satr=12;}
            else if ( satr == 3 ) {satr=1;}
            else if ( satr == 5 ) {satr=3;}
            else if ( satr == 8 ) {satr=5;}
            else if ( satr == 10 ) {satr=8;}
            else if ( satr == 12 ) {satr=10;}
            //else if ( satr == 14 ){satr=12;}
        }
        else if(action=='a' )
        {
            if ( soton == 1 ){soton=12;}
            else if ( soton == 3 ) {soton=1;}
            else if ( soton == 5 ) {soton=3;}
            else if ( soton == 8 ) {soton=5;}
            else if ( soton == 10 ) {soton=8;}
            else if ( soton == 12 ) {soton=10;}
            //else if ( soton == 14 ){soton=12;}
        }
        else if(action=='s' )
        {
            //if ( satr == 12 ){satr=14;}
            if ( satr == 10 ){satr=12;}
            else if ( satr == 8 ) {satr=10;}
            else if ( satr == 5 ) {satr=8;}
            else if ( satr == 3 ) {satr=5;}
            else if ( satr == 1 ) {satr=3;}
            else if ( satr == 12 ) {satr=1;}
        }
        else if(action=='d' )
        {
            //if ( soton == 12 ){soton=14;}
            if ( soton == 10 ){soton=12;}
            else if ( soton == 8 ) {soton=10;}
            else if ( soton == 5 ) {soton=8;}
            else if ( soton == 3 ) {soton=5;}
            else if ( soton == 1 ) {soton=3;}
            else if ( soton == 12 ) {soton=1;}
        }
        else if(action==13 && arr[satr][soton] == " ")
        {
            arr[satr][soton] = player ;
            temp[satr][soton] = player ;

            break;
        }

         temp[satr-1][soton] = "\u2550\u2550\u2550";
         temp[satr+1][soton] = "\u2550\u2550\u2550";

         temp[satr-1][soton-1] = "\u2554";
         temp[satr+1][soton+1] = "\u255d";
         temp[satr-1][soton+1] = "\u2557";
         temp[satr+1][soton-1] = "\u255a";

                                                                //A littel bug fix!
        if(soton==1 || soton==8)
         {
             temp[satr][soton-1] = "\u2551 "  ;
             temp[satr][soton+1] = " \u2551 "  ;
         }
         if(soton==3 || soton==10)
         {
            temp[satr][soton-1] = " \u2551 "  ;
            temp[satr][soton+1] = " \u2551 "  ;
         }
         if(soton==5 || soton==12)
         {
             temp[satr][soton-1] = " \u2551 ";
             temp[satr][soton+1] = " \u2551";
         }

        print(temp);
    }

} //endmove

int WinChecker (string Arr[14][14])
{
    // wincheckXO reads the number of x and o so we only need it when its 5
    int Result_X = winCheckXO(Arr , "x");
    int Result_O = winCheckXO(Arr , "o");
    int Q;

        if ((Result_X != 5) && (Result_O != 5 ))
            Q = 0;
        if ((Result_X == 5) && (Result_O == 5 ))
            Q = 3;
        if ((Result_X == 5) && (Result_O != 5 ))
            Q = 1;
        if ((Result_X != 5) && (Result_O == 5 ))
            Q = 2;

    return Q;

}

int winCheckXO( string Arr[14][14] , string player )             // win? => max = 5
{
    int num;
    int max;                // counts the number of a charackter x or o.
    string2d f1 = copyString(Arr);

                                           /////////////////// check kardan satr ha
    for(int i = 0 ; i<=5 ; i++)                  // 6 ta satr darim        for1=6dor
    {
        for(int j = 0 ; j<=1 ; j++)          // ya az khone 0 shoro mishe ya az khone 1         for2 = 2dor
        {
            num = 0 ;
            for(int k = j ; k<=j+4 ; k++) // for baraye check kardan 5 khane badi        for3 = 5 dor
            {
                if(f1[i][k] == player)
                    num++;
                else break;
            } // end for3

            if(num>max)
            max = num;
        } // end for2 baraye khone 0 ya 1
    } // end for1 baraye 6 ta satr

    if(max==5)
    return max;

                                          ////////////////////////// check kardan soton ha
    for(int j = 0 ; j<=5 ; j++)     // for1 = 6 dor    //6 soton darim
    {
        for(int i = 0 ; i<=1 ; i++)  // for2 = 2 dor    => ya az khone(satr) aval shoro mishe ya khone dovom
        {
            num = 0;
            for(int k=i ; k<=i+4 ; k++) //for3 = 5dor
            {
                if(f1[k][j]==player)
                    num++;
                else
                break ;

            }//end for3

            if(num>max)
                max =num;

        } //endfor2

        if(max==5)
        return max;

    } //end for1(soton ha)

    //              //////////////////////////////////////check kardan orib//////////////////////////////////////////////////

                               /* ghotr asli  va ghotr haye movazi ba on */
    for(int i = 0 ; i<=1 ; i++)       //ghotr asli     //for1 = 2 dor => start ba (0,0) ya (1,1)
    {
        num = 0;
        for(int j = i ; j<=i+4 ; j++) // for2= maximum 5 dor
        {
            if(f1[j][j]==player)
                num++;
            else
            break;

        }//end for2

        if(num>max)
        max=num;

    }//endfor1
    if(max==5)
        return max;

    num = 0;
    for(int i = 0 ; i<=4 ; i++)   // movazi balaye ghotr asli     // for1= 5 dor
    {
        if(f1[i][i+1]==player)
            num++;
        else
        break;

    }//end for1
    if(num>max)
        max=num;
    if(max==5)
        return max;

    num=0;
    for(int i=1 ; i<=5 ; i++) // movazi payin ghotr asli    //for1=5 dor
    {
        if(f1[i][i-1]==player)
           num++;
        else
        break;

    }//end for1
    if(num>max)
        max = num;
    if(max==5)
        return max;

               /* ghotr farE va ghotr haye movazi ba an */

     for(int i=0 ; i<=1 ; i++)    //ghotr farE // for1 = 2 dor => start ba (0,5) ya (1,4)
    {
        num = 0;
        for(int j=i ; j<= i+4 ; j++) //for2 = maximum 5 dor
        {
            if(f1[j][5-j]==player)
                num++;
            else break;

        }//endfor2

    if(num>max)
        max = num;

    }//endfor1

    if(max==5)
        return max;

    num = 0;
    for(int i=0 ; i<=4 ; i++)    // ghotr movazi balaye ghotr farE //for1=maximum 5 dor
    {
        if(f1[i][4-i]==player)
            num++;
        else
         break;

    }//endfor1
    if(num>max)
        max = num;

    if(max==5)
        return max;

    num = 0;
    for(int i = 1 ; i<=5 ; i++)  //ghotr mazi payine ghotr farE //for1=maximum 5 dor
    {
        if(f1[i][6-i]==player)
            num++;

        else
            break;

    }//endfor1

    if(num>max)
        max = num;

    if(max==5)
        return max;

     return max;

}

void MoveBlock(string (&arr)[14][14] , string player)
{
    int satr = 3 , soton = 3;


    string temp[14][14];
    for(int p1=0 ; p1<14 ; p1++)
        for(int p2=0 ; p2<14 ; p2++)
            temp[p1][p2]=arr[p1][p2];  // play with the copy !!!!

                // the very first graphics!
         temp[satr-3][soton] = "\u2550\u2550\u2550";
         temp[satr-3][soton-2] = "\u2550\u2550\u2550";
         temp[satr-3][soton+2] = "\u2550\u2550\u2550";
         temp[satr-3][soton+1] = "\u2564";
         temp[satr-3][soton-1] = "\u2564";
         temp[satr+3][soton] = "\u2550\u2550\u2550";
         temp[satr+3][soton-2] = "\u2550\u2550\u2550";
         temp[satr+3][soton+2] = "\u2550\u2550\u2550";
         temp[satr+3][soton+1] = "\u2567";
         temp[satr+3][soton-1] = "\u2567";

         temp[satr][soton-3] = "\u2551 "  ;
         temp[satr-2][soton-3] = "\u2551 "  ;
         temp[satr+2][soton-3] = "\u2551 "  ;
         temp[satr-1][soton-3] = "\u255f"  ;
         temp[satr+1][soton-3] = "\u255f"  ;
         temp[satr][soton+3] = " \u2551"  ;
         temp[satr-2][soton+3] = " \u2551"  ;
         temp[satr+2][soton+3] = " \u2551"  ;
         temp[satr-1][soton+3] = "\u2562"  ;
         temp[satr+1][soton+3] = "\u2562"  ;

         temp[satr-3][soton-3] = "\u2554";
         temp[satr+3][soton+3] = "\u255d";
         temp[satr-3][soton+3] = "\u2557";
         temp[satr+3][soton-3] = "\u255a";


    print(temp);

    while(1) // just do it :-)
    {

        string temp[14][14];
             for(int p1=0 ; p1<14 ; p1++)
                 for(int p2=0 ; p2<14 ; p2++)
                         temp[p1][p2]=arr[p1][p2];    //clear graphics


        char action = getch() ;


        system("cls");

        if(action=='w' )
        {
            if ( satr == 10 ) {satr=3;}
            else if ( satr == 3 ) {satr=10;}
        }
        else if(action=='a' )
        {
            if ( soton == 10 ) {soton=3;}
            else if ( soton == 3 ) {soton=10;}
        }
        else if(action=='s' )
        {
            if ( satr == 10 ) {satr=3;}
            else if ( satr == 3 ) {satr=10;}
        }
        else if(action=='d' )
        {
            if ( soton == 10 ) {soton=3;}
            else if ( soton == 3 ) {soton=10;}
        }
        else if(action=='l')
        {
            if (satr == 3 && soton == 3) {rotate(temp , 1 , 'L'); }
            if (satr == 3 && soton == 10) {rotate(temp , 2 , 'L');}
            if (satr == 10 && soton == 3) {rotate(temp , 3 , 'L'); }
            if (satr == 10 && soton == 10) {rotate(temp , 4 , 'L');}

            for (int i=0;i<14;i++)
                {for (int j=0;j<14;j++)
                    arr[i][j]=temp[i][j];}

            break;
        }
        else if(action=='r')
        {
            if (satr == 3 && soton == 3) {rotate(temp , 1 , 'R'); }
            if (satr == 3 && soton == 10) {rotate(temp , 2 , 'R'); }
            if (satr == 10 && soton == 3) {rotate(temp , 3 , 'R'); }
            if (satr == 10 && soton == 10) {rotate(temp , 4 , 'R'); }

            for (int i=0;i<14;i++)
                {for (int j=0;j<14;j++)
                        arr[i][j]=temp[i][j];}

            break;

        }

         temp[satr-3][soton] = "\u2550\u2550\u2550";
         temp[satr-3][soton-2] = "\u2550\u2550\u2550";
         temp[satr-3][soton+2] = "\u2550\u2550\u2550";
         temp[satr-3][soton+1] = "\u2564";
         temp[satr-3][soton-1] = "\u2564";
         temp[satr+3][soton] = "\u2550\u2550\u2550";
         temp[satr+3][soton-2] = "\u2550\u2550\u2550";
         temp[satr+3][soton+2] = "\u2550\u2550\u2550";
         temp[satr+3][soton+1] = "\u2567";
         temp[satr+3][soton-1] = "\u2567";

         temp[satr-3][soton-3] = "\u2554";
         temp[satr+3][soton+3] = "\u255d";
         temp[satr-3][soton+3] = "\u2557";
         temp[satr+3][soton-3] = "\u255a";
                                                // some bug fix!
 if(soton==1 || soton==8)
         { temp[satr][soton-3] = "\u2551 "  ;
         temp[satr-2][soton-3] = "\u2551 "  ;
         temp[satr+2][soton-3] = "\u2551 "  ;
         temp[satr-1][soton-3] = "\u255f"  ;
         temp[satr+1][soton-3] = "\u255f"  ;
         temp[satr][soton+3] = " \u2551"  ;
         temp[satr-2][soton+3] = " \u2551"  ;
         temp[satr+2][soton+3] = " \u2551"  ;
         temp[satr-1][soton+3] = "\u2562"  ;
         temp[satr+1][soton+3] = "\u2562"  ;   }

         if(soton==3 || soton==10)
         {
         temp[satr][soton-3] = "\u2551 "  ;
         temp[satr-2][soton-3] = "\u2551 "  ;
         temp[satr+2][soton-3] = "\u2551 "  ;
         temp[satr-1][soton-3] = "\u255f"  ;
         temp[satr+1][soton-3] = "\u255f"  ;
         temp[satr][soton+3] = " \u2551"  ;
         temp[satr-2][soton+3] = " \u2551"  ;
         temp[satr+2][soton+3] = " \u2551"  ;
         temp[satr-1][soton+3] = "\u2562"  ;
         temp[satr+1][soton+3] = "\u2562"  ;
         }

         if(soton==5 || soton==12)
         {
         temp[satr][soton-3] = "\u2551 "  ;
         temp[satr-2][soton-3] = "\u2551 "  ;
         temp[satr+2][soton-3] = "\u2551 "  ;
         temp[satr-1][soton-3] = "\u255f"  ;
         temp[satr+1][soton-3] = "\u255f"  ;
         temp[satr][soton+3] = " \u2551"  ;
         temp[satr-2][soton+3] = " \u2551"  ;
         temp[satr+2][soton+3] = " \u2551"  ;
         temp[satr-1][soton+3] = "\u2562"  ;
         temp[satr+1][soton+3] = "\u2562"  ;
         }

        print(temp);

    }

}

void MoveMenu( char &option)
{
    string arr[13][3] = {{"\u250c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2510"},
                          {"\u2502","       Play  Game       ","\u2502"},
                          {"\u251c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2524"},
                          {"\u2502","Instructions to the game","\u2502"},
                          {"\u251c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2524"},
                          {"\u2502","       How to play      ","\u2502"},
                          {"\u251c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2524"},
                          {"\u2502","         credits        ","\u2502"},
                          {"\u251c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2524"},
                          {"\u2502","         Ranking        ","\u2502"},
                          {"\u251c","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2524"},
                          {"\u2502","          Quit          ","\u2502"},
                          {"\u2514","\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500","\u2518"}
                          };

    int satr = 1 , soton = 1;
    char tap;

    string temp[13][3];
    for(int p1=0 ; p1<13 ; p1++)
        for(int p2=0 ; p2<3 ; p2++)
            temp[p1][p2]=arr[p1][p2];

         temp[satr-1][soton] = "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550";
         temp[satr+1][soton] = "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550";


         temp[satr][soton-1] = "\u2551"  ;

         temp[satr][soton+1] = "\u2551"  ;

         temp[satr-1][soton-1] = "\u2554";
         temp[satr+1][soton+1] = "\u255d";
         temp[satr-1][soton+1] = "\u2557";
         temp[satr+1][soton-1] = "\u255a";

    print133(temp);

    while(1)
    {
        string temp[13][3];
             for(int p1=0 ; p1<13 ; p1++)
                 for(int p2=0 ; p2<3 ; p2++)
                         temp[p1][p2]=arr[p1][p2];    //temp str


        char action = getch() ;

        system("cls");

        if(action=='w' )
        {
            if ( satr == 1 ){satr=11;}
            else if ( satr == 3 ){satr=1;}
            else if ( satr == 5 ){satr=3;}
            else if ( satr == 7 ){satr=5;}
            else if ( satr == 9 ){satr=7;}
            else if ( satr == 11 ){satr=9;}
        }
        else if(action=='a' )
        {
            if ( satr == 1 ){satr=11;}
            else if ( satr == 3 ){satr=1;}
            else if ( satr == 5 ){satr=3;}
            else if ( satr == 7 ){satr=5;}
            else if ( satr == 9 ){satr=7;}
            else if ( satr == 11 ){satr=9;}
        }
        else if(action=='s' )
        {
            if ( satr == 1 ){satr=3;}
            else if ( satr == 3 ){satr=5;}
            else if ( satr == 5 ){satr=7;}
            else if ( satr == 7 ){satr=9;}
            else if ( satr == 9 ){satr=11;}
            else if ( satr == 11 ){satr=1;}
        }
        else if(action=='d' )
        {
            if ( satr == 1 ){satr=3;}
            else if ( satr == 3 ){satr=5;}
            else if ( satr == 5 ){satr=7;}
            else if ( satr == 7 ){satr=9;}
            else if ( satr == 9 ){satr=11;}
            else if ( satr == 11 ){satr=1;}
        }
        else if(action==13)
        {
            if (satr == 1 ){tap = '1';}
            else if (satr == 3 ){tap = '2';}
            else if (satr == 5 ){tap = '3';}
            else if (satr == 7 ){tap = '4';}
            else if (satr == 9 ){tap = '5';}
            else if (satr == 11 ){tap = '6';}

    option = tap;
            break;

        }
         temp[satr-1][soton] = "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550";
         temp[satr+1][soton] = "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550";
         temp[satr][soton-1] = "\u2551"  ;
         temp[satr][soton+1] = "\u2551"  ;
         temp[satr-1][soton-1] = "\u2554";
         temp[satr+1][soton+1] = "\u255d";
         temp[satr-1][soton+1] = "\u2557";
         temp[satr+1][soton-1] = "\u255a";

        print133(temp);
    }
}

void rotate(string (&str)[14][14] , int block , char side)           // blocks :  1    2               sides:  R => saat gard
{                                                                  //            3    4                        L => pod saat gard
   string2d f1 = copyString(str);

   string3dar3 f2 = convertTo3(f1 , block);

   if(side=='R')
    clockWise(f2);

   if(side=='L')
     antiClockWise(f2);

    putBackto14(f2 , str , block);

}//endrotate

string3dar3 convertTo3(string2d f1 , int block)
{
    int i , j;    //baraye 6dar6
    static string tempArr[3][3];


    if(block==1)
    {
        i=0;
        j=0;
    }
    else if(block==2)
    {
        i=0;
        j=3;
    }
    else if(block==3)
    {
        i=3;
        j=0;
    }
    else if(block==4)
    {
        i=3;
        j=3;
    }

    for(int p=0 ; p<3 ; p++)
    {
        int k =j;
        for(int q=0 ; q<3 ; q++)
        {
            tempArr[p][q] = f1[i][k] ;
            k++;
        }
        i++;
    }

    return tempArr;
} // end copy to 3

void antiClockWise(string (&mat)[3][3])
{
    int x = 0;

    for(int y=0 ; y<2 ; y++)
    {
        string temp = mat[x][y];

        mat[x][y] = mat[y][2-x];

        mat[y][2 - x] = mat[2 - x][2 - y];

        mat[2 - x][2 - y]  = mat[2 - y][x];

        mat[2 - y][x] = temp ;

    }

}//end anti clock wise

void clockWise(string (&mat)[3][3])
{

    int x = 0;

    for(int y=0 ; y<2 ; y++)
    {
        string temp = mat[x][y];

        mat[x][y] = mat[2-y][x];

        mat[2-y][x] = mat[2-x][2-y];

        mat[2-x][2-y] = mat[y][2-x];

        mat[y][2-x] = temp;
    }

}//end clockWise

void putBackto14(string3dar3 f2 , string (arr)[14][14] , int block)
{
    int i , j;    //baraye 14

    if(block==1)
    {
        i=1;
        j=1;
    }
    else if(block==2)
    {
        i=1;
        j=8;
    }
    else if(block==3)
    {
        i=8;
        j=1;
    }
    else if(block==4)
    {
        i=8;
        j=8;
    }

    for(int p=0 ; p<3 ; p++)
    {
        int k = j;
        for(int q=0 ; q<3 ; q++)
        {
            arr[i][k] = f2[p][q];
            k+=2;
        }
        i+=2;

    }
}//end putback

void sortRanking()
{

       ifstream fin("./rank.txt" , ios::in );

        data temp[100] ;
        int j = 0;

    if(fin)
    {
        while(!fin.eof())                          // kkhandan file
        {

            fin>>temp[j].name;
            fin>>temp[j].win;
            fin>>temp[j].lost;
            fin>>temp[j].draw;

            j++;

        }
    }  //end khandan file

    for(int p = 0 ; p<=j-2 ; p++)
    for(int i = 0 ; i<=j-2 ; i++)
        {
                if(temp[i].name=="")
                    break;

                if(temp[i+1].name=="")
                    break;


                                        //swap arrays;
                int point0 = temp[i].win * 3 + temp[i].draw;
                int point1 = temp[i+1].win * 3 + temp[i+1].draw;
                ;


            if(point0==point1)
            {
                if(temp[i+1].win>temp[i].win)
                {
                    data m55;
                    m55.name = temp[i].name;
                    m55.win = temp[i].win;
                    m55.lost = temp[i].lost;
                    m55.draw = temp[i].draw;


                    temp[i].name = temp[i+1].name;
                    temp[i].win = temp[i+1].win;
                    temp[i].lost = temp[i+1].lost;
                    temp[i].draw = temp[i+1].draw;


                    temp[i+1].name = m55.name ;
                    temp[i+1].win = m55.win ;
                    temp[i+1].lost = m55.lost ;
                    temp[i+1].draw = m55.draw ;
                }

            }

            if(point1>point0)
            {

                data m55;
                m55.name = temp[i].name;
                m55.win = temp[i].win;
                m55.lost = temp[i].lost;
                m55.draw = temp[i].draw;

                temp[i].name = temp[i+1].name;
                temp[i].win = temp[i+1].win;
                temp[i].lost = temp[i+1].lost;
                temp[i].draw = temp[i+1].draw;

                temp[i+1].name = m55.name ;
                temp[i+1].win = m55.win ;
                temp[i+1].lost = m55.lost ;
                temp[i+1].draw = m55.draw ;}  //end if

        } //end swap va sort file




    ofstream fout("./rank.txt" , ios::out );        //rewrite to file
        for(int c = 0 ; c<= j-2 ; c++)
        {
            fout<<temp[c].name<<endl;
            fout<<temp[c].win<<endl;
            fout<<temp[c].lost<<endl;
            fout<<temp[c].draw<<endl;
        }
} //end sort ranking

void addToFile(string name , int w)                // w : 1=>win    2=>draw       //     0=>lost
{
        ifstream fin("./rank.txt" , ios::in );  //make a file in the same directory

        data temp[100] ;
        int i = 0;
        bool tekrari = false ;

    if(fin)
    {
        while(!fin.eof())       //check if we are not at the end of the file
        {
            fin>>temp[i].name;
            fin>>temp[i].win;
            fin>>temp[i].lost;
            fin>>temp[i].draw;

            if(temp[i].name==name)
            {

                if(w==1)
                    temp[i].win +=1;

                if(w==0)
                    temp[i].lost +=1;

                if(w==2)
                    temp[i].draw +=1;


                tekrari = true ;

                //cout<<endl<<"winshod"<<temp[i].draw<<endl;
            }

            i++;

        }
}

if(tekrari)
    {
        ofstream fout("./rank.txt" , ios::out );
        for(int j = 0 ; j <= i-2 ; j++)
        {

            fout<<temp[j].name<<endl;
            fout<<temp[j].win<<endl;
            fout<<temp[j].lost<<endl;
            fout<<temp[j].draw<<endl;
        }


    }


if(!tekrari)
{
    ofstream fout2("./rank.txt" , ios::out | ios::app);


    fout2<<name<<endl;
    int win = 0;
    int lost = 0;
    int draw = 0;

    if(w==1)
    win=1;

    if(w==2)
    draw=1;

    if(w==0)
    lost=1;

    fout2<<win<<endl;
    fout2<<lost<<endl;
    fout2<<draw<<endl;

fout2.close();
}
}//end add to file

void print_ranking()
{
    {cout<<"\u2502";
    cout.width(8);
    cout.setf(ios::left);
    cout<<"  Rank";}

    {cout<<"\u2502";
    cout.width(16);
    cout.setf(ios::left);
    cout<<"      Name";}

    {cout<<"\u2502";
    cout.width(7);
    cout.setf(ios::left);
    cout<<"  Win";}

    {cout<<"\u2502";
    cout.width(7);
    cout.setf(ios::left);
    cout<<" Lost";}

    {cout<<"\u2502";
    cout.width(7);
    cout.setf(ios::left);
    cout<<" Draw";}

    {cout<<"\u2502";
    cout.width(7);
    cout.setf(ios::left);
    cout<<" Point";}
    cout<<"\u2502"<<endl;


    int counter = 0;
    data datafortype ;
    ifstream f4("./rank.txt" , ios::in) ;


    while(!f4.eof())
    { counter++;

        string tempname ;
        int win;
        int lost;
        int draw;
        f4>>tempname;
        f4>>win;
         f4>>lost;
         f4>>draw;

        if(tempname == "")
            break;

        {cout<<"\u2502";
        cout.width(8);
        cout.setf(ios::left);
        cout<<counter;}

        {cout<<"\u2502";
        cout.width(16);
        cout.setf(ios::left);
        cout<<tempname;}

        {cout<<"\u2502";
        cout.width(7);
        cout.setf(ios::left);
        cout<<win;}

        {cout<<"\u2502";
        cout.width(7);
        cout.setf(ios::left);
        cout<<lost;}

        {cout<<"\u2502";
        cout.width(7);
        cout.setf(ios::left);
        cout<<draw;}

        {cout<<"\u2502";
        cout.width(7);
        cout.setf(ios::left);
        cout<< win * 3 + draw;}
        cout<<"\u2502"<<endl;
    }
}
