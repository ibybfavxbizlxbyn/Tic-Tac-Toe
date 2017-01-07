#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>

using namespace std;

bool step;
char pole[3][3];
char name1[10];
char name2[10];

int start();
bool input(int AI);
bool win();
void print(bool header);
int AI_step();

int main()
{
    srand(time(NULL));
    const unsigned short mode = start();
    system("cls");
    print(true);

    cin.get();
    cout << "Enter name of first player: ";
    cin.getline(name1, 10);
    if (mode == 0)
    {
        cout << "Enter name of second player: ";
        cin.getline(name2, 30);
    } else
    {
        name2 = {'C', 'o', 'm', 'p', 'u', 't', 'e', 'r'};
    }

    system("cls");
    print(true);
    if (rand() % 2 == 0)
    {
        cout << name1 << " go first." << endl;
        step = false;
    } else
    {
        cout << name2 << " go first." << endl;
        step = true;
    }
    _getch();

    unsigned short step_num = 0;
    while (!win())
    {
        if (step_num == 9)
            break;
        system("cls");
        if (mode == 0)
        {
            if (!input(0))
            {
                cout << "Error: wrong input of data;" << endl;
                _getch();
            }
        } else
        {
            if (step)
            {
                short k = 1;
                if (mode == 1)
                {
                    while (!input(k))
                    {
                        k = rand()%10+1;
                    }
                } else
                {
                    k = AI_step();
                    if (k != 0)
                    {
                        input(k);
                    } else
                    {
                        while (!input(k))
                        {
                            k = rand()%10;
                        }
                    }
                }
            } else
            {
                if (!input(0))
                {
                    cout << "Error: wrong input of data;" << endl;
                }
            }
        }
        step_num++;
    }

    system("cls");
    print(true);
    cout << endl;
    if (!win())
    {
        cout << "Draw!" << endl;
    } else
    if (step)
    {
        cout << name1 << " win!" << endl;
    } else
    {
        cout << name2 << " win!" << endl;
    }

    _getch();

    return 0;
}

void print(bool header)
{
    if (header)
    {
        cout << "\t\t*** Tic Tac Toe ***\n\n";
    }
    for (short i = 0; i < 3; i++)
    {
        cout << " ";
        for (short j = 0; j < 3; j++)
        {
            cout << "| " << pole[i][j] << " ";
        }
        cout << "| " << endl << endl;
    }
}

int start()
{
    short l = 0;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++, l++)
        {
            pole[i][j] = 49+l;
        }
    }
    while (true)
    {
        cout << "\t\t*** Tic Tac Toe ***\n\n";
        cout << "1. Player vs AI;" << endl;
        cout << "2. Players vs player" << endl;
        cout << "Chose game mode: ";
        unsigned short choise;
        cin >> choise;
        if (choise == 1)
        {
            choise = 0;
            while (true)
            {
                system("cls");
                cout << "\t\t*** Tic Tac Toe ***\n\n";
                cout << "1. Player vs AI;" << endl;
                cout << "   1)Low level AI;" << endl;
                cout << "   2)High level AI;" << endl;
                cout << "2. Players vs player" << endl;
                cout << "Chose AI level: ";
                cin >> choise;
                if (choise != 1 && choise != 2)
                {
                    cout << "Error: wromg input of data;" << endl;
                    _getch();
                    system("cls");
                } else
                    break;
            }

            system("cls");
            cout << "\t\t*** Tic Tac Toe ***\n\n";
            cout << "   Rules: " << endl;
            cout << "You play with computer on game pole 3x3." << endl;
            cout << "Wins the one who make a winning combination." << endl;
            cout << "Game pole: " << endl << endl;
            print(false);
            cout << endl;
            cout << "To make a step press button with a number of a pole." << endl;
            cout << "Press any key to start" << endl;
            _getch();
            system("cls");
            if (choise == 1)
            {
                return  1;
            } else
            {
                return 2;
            }
        } else
        if (choise == 2)
        {
            system("cls");
            cout << "\t\t*** Tic Tac Toe ***\n\n";
            cout << "   Rules: " << endl;
            cout << "2 users play on game pole 3x3." << endl;
            cout << "Wins the one who make a winning combination." << endl;
            cout << "Game pole: " << endl << endl;
            print(false);
            cout << endl;
            cout << "To make a step press button with a number of a pole." << endl;
            cout << "Press any key to start" << endl;
            _getch();
            system("cls");
            return 0;
        } else
        {
            cout << "Error: wrong input of data;" << endl;
            _getch();
            system("cls");
        }
    }
}

bool input (int AI)
{
    system("cls");
    print(true);

    if (!step)
    {
        cout << name1 << " go: ";
    } else
    if (!AI)
    {
        cout << name2 << " go: ";
    } else
    {
        cout << "Computer go." << endl;
    }

    short i, j;
    unsigned short k;
    if (!AI)
    {
        cin >> k;
    } else
    {
        k = AI;
    }

    if (k < 1 || k > 9)
        return false;

    if (k % 3 == 0)
    {
        i = k/3-1;
        j = 2;
    } else
    {
        i = k/3;
        j = k%3-1;
    }

    if (pole[i][j] == 'X' || pole[i][j] == 'O')
        return false;

    if (!step)
    {
        pole[i][j] = 'X';
        step = true;
    } else
    {
        pole[i][j] = 'O';
        step = false;
    }

    cin.get();
    return true;
}

bool win()
{
    for (short i = 0; i < 3; i++)
    {
        if ((pole[i][0] == pole[i][1]) && (pole[i][1] == pole[i][2]))
            return true;
        if ((pole[0][i] == pole[1][i]) && (pole[1][i] == pole[2][i]))
            return true;
    }
    if ((pole[0][0] == pole[1][1]) && (pole[1][1] == pole[2][2]))
        return true;
    if ((pole[0][2] == pole[1][1]) && (pole[2][0] == pole[1][1]))
        return true;
    return false;
}

int AI_step()
{
    char pole_copy[3][3];
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            pole_copy[i][j] = pole[i][j];
        }
    }

    for (short k = 1; k <= 9; k++)
    {
        unsigned short i, j;
        if (k % 3 == 0)
        {
            i = k/3-1;
            j = 2;
        } else
        {
            i = k/3;
            j = k%3-1;
        }
        if (pole_copy[i][j] != 'X' && pole_copy[i][j] != 'O')
        {
            if (!step)
            {
                pole_copy[i][j] = 'X';
            } else
            {
                pole_copy[i][j] = 'O';
            }
            if (win())
            {
                return k;
            } else
            {
                pole_copy[i][j] = k;
            }
        }
    }
    return 0;
}
