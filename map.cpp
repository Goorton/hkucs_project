#include "map.h"
#include "screen.h"
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
#include "./include/ncursestw/curses.h"
using namespace std;

//** This file is used to generate interfaces **
//** There are mainly 4 interfaces in our game **

//Below is the 1st interface: the map.
//In our game, there is a random event that each game the map will be different.
//So we use 2 functions to implement random map.

//function 1: generate a general map.
void map::initializemap()
{
	clear();
	for (int i = 0; i < 116; i++)
	{
		coutsquare(wallbreak[i][0], wallbreak[i][1]);
		usleep(13500);
	}
}
//function 2: generate random bricks.
void map::initializerandbreak(int r){
	for (int m = 0; m < 16; m++) {
		if (randbreak[r][m][0] != 0) {
			coutsquare(randbreak[r][m][0], randbreak[r][m][1]);
			usleep(13500);
		}
	}
	//setcursor(31, 30);
}

//Below is the 2nd interface: the start menu.
void map::initializemenu()
{
	setcursor(36, 10, "        ");
	setcursor(36, 13, "       ");
	setcursor(36, 16, "    ");
	setcursor(36, 18, "                 ");
	setcursor(36, 10, "Start New Game");
	setcursor(36, 13, "Load Game");
	setcursor(33, 3, "Highest score: ");
	setcursor(33, 5, "Your score: ");
	setcursor(33, 19, "Press <w><a><s><d> to move");
	setcursor(33, 21, "Press <y> to choose");
	setcursor(33, 23, "Press <q> to open gamemenu");
}

//Below is the 3rd interface: the game menu.
void map::gamemenu()
{
	setcursor(36, 10, "              ");
	setcursor(36, 13, "         ");
	setcursor(33, 19, "                          ");
	setcursor(33, 21, "                   ");
	setcursor(33, 23, "                          ");
	setcursor(36, 10, "Continue");
	setcursor(36, 13, "Restart");
	setcursor(36, 16, "Save");
	setcursor(33, 21, "Press <y> to choose");
}

//Below is the 4th interface: gameover interface.
void map::gameover() {
	clear();
	setcursor(22, 17, "GAME OVER!!");
}
