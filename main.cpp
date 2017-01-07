#include "header.h"

bool step;
char pole[3][3];
char name1[10];
char name2[10];

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
        cin.getline(name2, 10);
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
                short k = 5;
                if (mode == 1)
                {
                    while (!input(k))
                    {
                        k = rand()%10+1;
                    }
                } else
                {
                    input(AI_step());
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

