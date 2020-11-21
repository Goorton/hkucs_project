#include <unistd.h>
#include "./include/ncursestw/curses.h"
#include "screen.h"
#include <stdlib.h>
#include "controller.h"
using namespace std;

//** This file is used to perform "Choice" function **
//** That is, to decide which choice the user have made **

//This funcion is combined with function"initializemenu()" in map.h.
//key == 1: user choose to start a new game.
//key == 2: user choose to load a game.
int menuselect()
{
	int ch;
	int key;
	bool ifenter = false;
	key = 1;
	coutpointer(33, 10);
	refresh();
	while (true)
	{
		ch = getch();
		switch (ch)
		{
		case 'w': //Arrow key: up
			if (key == 2) {
				coutclear(33, 13);
				refresh();
				coutpointer(33, 10);
				refresh();
				key = 1;
				break;
			}
			break;

		case 's': //Arrow key: down
			if (key == 1) {
				coutclear(33, 10);
				refresh();
				coutpointer(33, 13);
				refresh();
				key = 2;
				break;
			}
			break;

		case 'y': //enter
			ifenter = true;
			break;
		}

		if (ifenter) {
			return key;
		}
	}
}

//This funcion is combined with function"gamemenu()" in map.h.
//gkey == 1: user choose to continue.
//gkey == 2: user choose to restart.
//gkey == 3: user choose to save data.
int gamemenuselect() {
	int ch;
	bool ifenter = false;
	int gkey = 1;
	coutpointer(33, 10);
	refresh();
	while (true)
	{
		ch = getch();
		switch (ch)
		{
		case 'w': //Arrow key: up
			if (gkey > 1) {
				switch (gkey)
				{
				case 2:
					coutclear(33, 13);
					refresh();
					coutpointer(33, 10);
					refresh();
					gkey = 1;
					break;
				case 3:
					coutclear(33, 16);
					refresh();
					coutpointer(33, 13);
					refresh();
					gkey = 2;
					break;
				}
			}
			break;

		case 's': //Arrow key: down
			if (gkey < 3) {
				switch (gkey)
				{
				case 1:
					coutclear(33, 10);
					refresh();
					coutpointer(33, 13);
					refresh();
					gkey = 2;
					break;
				case 2:
					coutclear(33, 13);
					refresh();
					coutpointer(33, 16);
					refresh();
					gkey = 3;
					break;
				}
			}
			break;

		case 'y': //enter
			ifenter = true;
			coutclear(33, 10);
			coutclear(33, 13);
			coutclear(33, 16);
			refresh();
			break;
		}

		if (ifenter) {
			return gkey;
		}
	}
}
