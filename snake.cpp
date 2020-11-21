#include <unistd.h>
#include "snake.h"
#include "screen.h"
#include "./include/ncursestw/curses.h"
#include <ctime>
#include <stdlib.h>
#include <fstream>
using namespace std;

//** This is a large file including functions about snake and food **

//This function is used to initialize the snake and score.
//Default: the snake is generated at the left part of the map.
void snake::initializesnake() {
	direction = 'r';//Default direction: right.
	slen = 2;
	head->x = 3;
	head->y = 15;
	tail->x = 2;
	tail->y = 15;
	head->next = tail;
	tail->next = NULL;
	coutcircle(3, 15);
	refresh();
	coutcircle(2, 15);
	refresh();
	score = 0;//Initialize score.
}

//This function is used to perform snake's movement.
//We add a new node before head and delete the node at tail.
//Depending on the direction of movement, the new node could have different position.
void snake::movesnake() {
	sbody* current = head;
	while (current->next != NULL) {
		coutclear(current->x, current->y);
		refresh();
		current = current->next;
	}
	coutclear(current->x, current->y);//delete the tail.
	refresh();
	sbody* m = new sbody;
	m->next = head;
	switch (direction)
	{
	case 'u':
		m->x = head->x;
		m->y = head->y - 1;
		break;
	case 'd':
		m->x = head->x;
		m->y = head->y + 1;
		break;
	case 'l':
		m->x = head->x - 1;
		m->y = head->y;
		break;
	case 'r':
		m->x = head->x + 1;
		m->y = head->y;
		break;
	}
	head = m;//add a new node and let it be the head.




	current = head;
	for (int i = 0; i < slen - 1; i++) {
		current = current->next;
	}
	lx = current->next->x;
	ly = current->next->y;//lx, ly is snake's tail's position. Help to determine the position of the tail when snake gets longer.

	//After deciding the new position of the snake, we print it out on the map.
	current->next = NULL;
	current = head;
	while (current->next != NULL) {
		coutcircle(current->x, current->y);
		refresh();
		current = current->next;
	}
	coutcircle(current->x, current->y);
	refresh();
}

//This function is used to determine if the snake is dead or not.
//If dead: return true; not dead: return false.
//We need the map type r to decide the position of random brick.
bool snake::death(int r) {
	int hx, hy;//Define the position of the head for convenience.
	hx = head->x;
	hy = head->y;

	//if the snake touches the basic map, it dies.
	if ((hx > 29) || (hx < 2) || (hy > 29) || (hy < 2)) {
		return true;
	}

	//if the snake touches the random brick, it dies.
	//We need the map type r to decide the position of random brick.
	switch (r)
	{
	case 0:
		for (int i = 0; i < 4; i++) {
			if ((hx == randbreak[0][i][0]) && (hy == randbreak[0][i][1])) {
				return true;
			}
		}
		break;
	case 1:
		for (int i = 0; i < 16; i++) {
			if ((hx == randbreak[1][i][0]) && (hy == randbreak[1][i][1])) {
				return true;
			}
		}
		break;
	case 2:
		for (int i = 0; i < 8; i++) {
			if ((hx == randbreak[2][i][0]) && (hy == randbreak[2][i][1])) {
				return true;
			}
		}
		break;
	case 3:
		for (int i = 0; i < 12; i++) {
			if ((hx == randbreak[3][i][0]) && (hy == randbreak[3][i][1])) {
				return true;
			}
		}
		break;
	}

	//if the snake touches itself, it dies.
	sbody* current = head->next;
	for (int i = 0; i < slen-1; i++) {
		if ((current->x == hx) && (current->y == hy)) {
			return true;
		}
		current = current->next;
	}
	return false;
}

//This function is used to keep listening keyboard while do not stop snake's movement
//Use man select to choose one: no input in buffer within 80000 ns: continue execution; else: return the input. 
int mygetch(){
	fd_set rfds;
	struct timeval tv;
	int retval;
	int ch;

	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	tv.tv_sec =0;
	tv.tv_usec = 80000;

	retval = select(1, &rfds, NULL, NULL, &tv);
	ch = 0;
	if (retval == -1){
		perror("select()");
	}
	else if (retval){
		ch = getch();
		setbuf(stdin, NULL);
	}
	else{
	}
	return ch;
}
//This function is used to decide if the snake has changed its position.
//Also the return value can help find if the user has pressed 'q'.
bool snake::changedirection(){
	char ch;
	ch = mygetch();//if we get return value, then decide what it is.
	switch (ch)
	{
	case 'w':
			if (direction != 'd') { //snake can not turn down if it is going up. Same below.
				direction = 'u';
			}
			return true;
			break;
	case 's':
			if (direction != 'u') {
				direction = 'd';
			}
			return true;
			break;
	case 'a':
			if (direction != 'r') {
				direction = 'l';
			}
			return true;
			break;
	case 'd':
			if (direction != 'l') {
				direction = 'r';
			}
			return true;
			break;


	case 'q'://If user pressed key: 'q', then return false.
			return false;

		default:
			return true;

		}

	return true;
}

//This function is used to generate random food in the map.
//We need the map type r to decide the position of random brick, where the food can not generate.
void snake::food(int r) {
	int n;
	bool able = true;
	switch (r)
	{
	case 0:
		n = 8;
		break;
	case 1:
		n = 16;
		break;
	case 2:
		n = 4;
		break;
	case 3:
		n = 12;
		break;
	}

	sbody* current = head;
	srand(time(NULL));
	fx = rand() % 28 + 2;
	fy = rand() % 28 + 2;
	while (true) {
		for (int i = 0; i < n; i++) {
			if ((fx == randbreak[r][i][0]) && (fy == randbreak[r][i][1])) {
				able = false;
			}
		}
		while (current->next != NULL) {
			if ((fx == current->x) && (fy == current->y)) {
				able = false;
				break;
			}
			current = current->next;
		}
		if (able) {
			break;
		}
		else {
			srand(time(NULL));
			fx = rand() % 28 + 2;
			fy = rand() % 28 + 2;
		}

	}
	coutfood(fx, fy);
	refresh();
}

//This function is used to determine if snake has eaten the food.
//Also, the function will update "score", and compare it with "Highest score" stored in "Record.txt".
//If "score" is higher than "Highest score", then update "Record.txt".
bool snake::eatfood() {
	if ((head->x == fx) && (head->y == fy)) {
		score += 10;//update "score".
		mvprintw(5, 66, "Your score: %d", score);
		refresh();
		int s;
		ifstream fin;
		ofstream fout;
		fin.open("Record.txt");
		fin >> s;
		fin.close();
		if (score > s) {
			s = score;
			fout.open("Record.txt");
			fout << s;//update "Highest score".
			fout.close();
		}
		mvprintw(3, 66, "Highest score: %d", s);
		refresh();
		return true;
	}
	return false;
}

//This function is used to perform the function that get snake longer.
void snake::longer() {
	sbody* current = head;
	sbody* p = new sbody;
	p->x = lx;
	p->y = ly;//add a new node at the end of the tail.
	p->next = NULL;
	for (int i = 0; i < slen-1; i++) {
		current = current->next;
	}
	current->next = p;
	slen += 1;
}

//This function is used to store the snakebody's position into "snakebodystore.txt".
void snake::save() {
	ofstream fout;
	fout.open("snakebodystore.txt");

	if (fout.fail()) {
		setcursor(36, 18, "Error: Not Saved!");
		refresh();
	}
	else {
		sbody* current = head;
		fout << slen << ' ' << direction << ' ' << score << ' ' << lx << ' '<< ly << ' ';
		for (int i = 0; i < slen - 1; i++) {
			fout << current->x << ' ' << current->y << ' ';
			current = current->next;
		}
		fout << current->x << ' ' << current->y << ' ';
		fout.close();
		setcursor(36, 18, "Successful Saved!");
		refresh();
	}

}

//This function is used to load the snakebody's position from "snakebodystore.txt".
void snake::loadsnake() {
	int a, b;
	ifstream fin;
	fin.open("snakebodystore.txt");
	sbody* p = new sbody;

	if (fin.fail()) {
		setcursor(36, 18, "Loading Error!!!!");
		refresh();
	}

	else {
		fin >> slen >> direction >> score >> lx >> ly;
		fin >> p->x >> p->y;
		p->next = NULL;
		head = p;
		for (int i = 0; i < slen - 1; i++) {
			fin >> a >> b;
			snake::buildsnake(a, b);
		}
		coutcircle(head->x, head->y);
		refresh();

	}

}

//This function help build the snakebody when loading.
void snake::buildsnake(int a, int b) {
	sbody* p = new sbody;
	p->x = a;
	p->y = b;
	sbody* current = head;
	p->next = NULL;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = p;
	coutcircle(p->x, p->y);
	refresh();
}
