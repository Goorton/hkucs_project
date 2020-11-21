#ifndef SCREEN_H
#define SCREEN_H


//** This file is used to set console cursor to where we want **
//** For convenience, we add some more functions to quickly print out elements in our game **

void setcursor(const int x, const int y, const char* a);
void coutsquare(const int x, const int y);
void coutcircle(const int x, const int y);
void coutpointer(const int x, const int y);
void coutclear(const int x, const int y);
void coutfood(const int x, const int y);

#endif // SCREEN_H
