#include "map.h"
#include "./include/ncursestw/curses.h"
#include "controller.h"
#include "snake.h"
#include "screen.h"
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

//** This file is the main file executing the game **
//** We decide two while circle to implement the function **

int main(){
	//Set terminal.
	//Declare m, s.
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	map m;
	snake s;
	int r;
	int command;
	int rerun;

	ofstream fout;
	ifstream fin;

	while (true) { //Keep doing the following instruction until the terminal is closed.
		rerun = 0;
		srand(time(NULL));
		r = rand() % 4; //Generate a seed to generate a random map.
		m.initializemap();
		m.initializemenu();
		m.initializerandbreak(r);
		if (menuselect() == 2) {   //return 2 means to load a game.
			setcursor(36, 18, "Loading Error!!!!");
			refresh();
			fin.open("foodwall.txt");
			if (fin.fail()) {
				setcursor(36, 18, "Loading Error!!!!");
				refresh();
			}
			else {
				fin >> r;//Load a seed.
			}
			fin.close();

			clear();
			refresh();
			erase();
			refresh();
			m.initializemap();
			m.initializemenu();
			m.initializerandbreak(r);
			s.loadsnake();
			s.food(r);
			sleep(1);

		}
		else {
			s.initializesnake();
			s.food(r);
		}


		while (s.death(r) != true) {
			if (s.changedirection() != true) {
				m.gamemenu();
				if (command = gamemenuselect()) {
					switch (command)
					{
					case 1:
						m.initializemenu();
						break;
					case 2:
						rerun = 1;
						break;
					case 3:
						s.save();

						fout.open("foodwall.txt");
						if (fout.fail()) {
							setcursor(36, 18, "Error: Not Saved!");
							refresh();
						}
						else {
							fout << r;
						}
						fout.close();
						m.initializemenu();
						break;
					}


				}
			}
			if (rerun == 1) {
				break;
			}
			if (s.eatfood()) {
				s.longer();
				s.food(r);
			}
			s.movesnake();
			usleep(135000);
		}

		//if choose "restart", then no gameover interface.
		if (rerun != 1) {
			m.gameover();
			sleep(3);

		}

	}

	endwin();
	return 0;
}
