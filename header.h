#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using std :: cout;
using std :: cin;
using std :: endl;

int start();
bool input(int AI);
bool win();
void print(bool _header);
int AI_step();

#endif // HEADER_H_INCLUDED
