#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>

using namespace std;

bool step;
char pole[3][3];
char name1[10];
char name2[10];

void start();
bool input();
bool win();
void print(bool header);

int main()
{
    srand(time(NULL));
    start();
    system("cls");
    print(true);

    cout << "Enter name of first player: ";
    cin.getline(name1, 30);
    cout << "Enter name of second player: ";
    cin.getline(name2, 30);
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

    while (!win())
    {
        system("cls");
        if (!input())
        {
            cout << "Error: wrong input of data;" << endl;
            _getch();
        }
    }

    system("cls");
    print(true);
    cout << endl;
    if (!win())
    {
        cout << "\tDraw!" << endl;
    } else
    if (!step)
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
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << "| " << pole[i][j] << " ";
        }
        cout << "| " << endl << endl;
    }
}

void start()
{
    int l = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++, l++)
        {
            pole[i][j] = 49+l;
        }
    }

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
}

bool input ()
{
    system("cls");
    print(true);

    if (!step)
    {
        cout << name1 << " go: ";
    } else
    {
        cout << name2 << " go: ";
    }
    int i, j;
    int k;
    cin >> k;
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

    return true;
}

bool win()
{
    for (int i = 0; i < 3; i++)
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
