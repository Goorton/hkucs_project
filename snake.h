#ifndef SNAKE_H
#define SNAKE_H

//** This is a large file including functions about snake and food **

//To better encapsulate functions, we define a class: snake.
class snake 
{
public:
	//score is a variable changing during game process.
	//And we need to decide if score is larger than "Highest Score" during the game.
	int score = 0;

	//These 5 functions are used to perform basic ability of the snake.
	//Including: initialization; movement; decide if it is dead;
	//decide whether the user have changed the direction of movement; make snake longer after eating food.
	void initializesnake();
	void movesnake();
	bool death(int r);
	bool changedirection();
	void longer();

	//These 2 functions are used to perform basic ability of food.
	//Including: generate food; decide if snake eats the food.
	void food(int r);
	bool eatfood();

	//These 3 functions are usede to perform basic saveload.
	//Including: save the position of snake; load the position of snake; generate the loading snake.
	void save();
	void loadsnake();
	void buildsnake(int a, int b);

private:
	//This is the rand bricks' position. We need it to decide where the food can not generate.
	int randbreak[4][16][2] = {
		{{2, 2}, {29, 2}, {2, 29}, {29, 29}},
		{{2, 2}, {2, 3}, {3, 2}, {3, 3}, {28, 2}, {28, 3}, {29, 2}, {29, 3}, {2, 28}, {2, 29}, {3, 28}, {3, 29}, {28, 28}, {28, 29}, {29, 28}, {29, 29}},
		{{3, 4}, {4, 3}, {27, 3}, {28, 4}, {3, 27}, {4, 28}, {28, 27}, {27, 28}},
		{{15, 2}, {16, 2}, {15, 3}, {16, 3}, {15, 4}, {16, 4}, {15, 29}, {16, 29}, {15, 28}, {16, 28}, {15, 27}, {16, 27}} };

	int fx, fy;//food position.
	int lx = 2, ly = 15;//snake's tail's position. Help to determine the position of the tail when snake gets longer.
	int slen = 2;//snake's length.

	//This is the direction of snake's movement.
	//'u'stands for up; 'd'stands for down; 'l'stands for left; 'r'stands for right.
	char direction;

	//This is the body of the snake.
	//We use linked list to build the snake.
	//This way, we can simply implement "movement" function and "longer" function. 
	struct sbody
	{
		int x, y;//The position of the body.
		sbody* next;
	};

	//Initialize head and tail.
	sbody* head = new sbody;
	sbody* tail = new sbody;
	
};


#endif // SNAKE_H
