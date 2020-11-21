#include "screen.h"
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include "./include/ncursestw/curses.h"
using namespace std;

//** This file is used to set console cursor to where we want **
//** For convenience, we add some more functions to quickly print out elements in our game **

//set console cursor to a point
void setcursor(const int x, const int y, const char* a) {
	mvaddstr(y, x*2, a);
	refresh();
}

//set console cursor to a point and print out "��", which means wall in our game.
void coutsquare(const int x, const int y) {
	mvaddstr(y, x*2, "##");
	refresh();
}

//set console cursor to a point and print out "��", which means snake body in our game.
void coutcircle(const int x, const int y) {
	mvaddstr(y, x*2, "::");
	refresh();
}

//set console cursor to a point and print out "��", which is a pointer in our game.
void coutpointer(const int x, const int y) {
	mvaddstr(y, x*2, "->");
	refresh();
}

//set console cursor to a point and print out "��", which means food in our game.
void coutfood(const int x, const int y) {
	mvaddstr(y, x*2, "@@");
	refresh();
}

//set console cursor to a point and print out a space, which is used to clear the output in our game.
void coutclear(const int x, const int y) {
	mvaddstr(y, x*2, "  ");
	refresh();
}
