# COMP2113_Group Project
## **Final work**

Group number: **Group 72**
 
Team member: 
** Wu Anzhi 3035718840
** Yang Guo 3035637670

Name of game: **Snake**
 
Game description:
* This is a console program.
* **Snake** is a game where players can manipulate a "snake" (consisting of strings) in "map" (a limited area). 
* The "snake" can move in four directions and get "food" to get longer. 
* The longer the "snake", the higher scores the player can get. 
* If the "snake" hit the edges, itself or the bricks, game over.
* Press 'w''s''a''d' to move, 'w''s' to select in a menu, 'y' to make decision, 'q' to call gamemenu.
 
Basic rules:
* A closed space surrounded by four walls
* The "snake" can move in four directions -- upward, downward, rightward, leftward.
* The "snake" can become longer if its head touches "food" (the target points).
* The "food" will appear randomly.
* The "snake" can only move within "map".
* If head of the "snake" hit the walls, its body or bricks, game over.
 
**Implemented** Features:
1. Generation of random game sets or events
* the "food" appears randomly. 
* generate random bricks for every game. 

2. Data structures for storing game status
* Array: used to store 
  - positions of walls
  - random bricks
  - position of "food"
* Linked list: used to store 
  - the body of the "snake"
 
3. Dynamic memory management
  - use pointer and address to locate every body of the "snake"
  - keyboard listener

4. File input/output (e.g., for loading/saving game status)
* Loading/Saving: 
  - position of the "snake"
  - position of the "food"
  - type of the map
  - highest scores
 
5. Program codes in multiple files
* We divide the game into many small parts

  - main.cpp: 
    * Initialize screen, type of the map
    * Declare necessary parameter
    * Game Level One Loop & Level Two Loop
    * Perform I/O interaction
    * React to decision (return value come from <controller>)
 
  - controller.cpp & controller.h: 
    * Monitor keyboard
    * Perform selection
    
  - map.cpp & map.h: 
    * Initialize map and bricks
    * Initialize basic menu (Start new game/ Load game/ Exit)
    * Initialize gamemenu (Continue/ restart/ save)
    * Gameover interface
 
  - snake.cpp & snake.h: 
    * Build up snake body (Linked lists)
    * Perform Movement
    * Monitor keyboard and decide the direction of movement
    * Randomly generate food
    * Judge if snake dead
    * Judge if snake get food, and perform "get longer"
    * Perform I/O operation: save & load snake body position
 
  - screen.cpp & screen.h: 
    * Perform screen output at desired position
    * Output elements conveniently

  
Non-standard Libraries:
  * unistd.h: sleep(), usleep().
    we use this library to perform "pause" effect, and thus perform the movement of the snake, animation effects during map generation, initialization of gameover interface. Also, use usleep() to help perform non-blocking selection.
    
  * curses.h (git clone from https://github.com/mirror/ncurses.git): initilize the screen, perform screen output and animation effects
   we use this library in a wide range to perform screen output. The initialization of map, bricks, words, food, snake body, cursor, menu, gameover interface and etc. Everything output on the terminal is completed with this library. We mainly use: initscr(), endwin(), mvaddstr(y, x, string) to implement functions above.
  
   PS: to further implement our game in different working environment, we substitute "curses.h" with "windows.h" to run this game under windows environment.
   
   
   
Compilation and execution instructions:
  1. Put all all files (4 ".h" files, 5 ".cpp" files, 3 ".txt" files, 1 "Makefile") under the same directory.
  2. Check if installed <curses.h> or not: if not, git clone a new one in this directory. if yes: substitute the header line #include "./include/ncursestw/curses.h" with #include <curses.h>, and then modify the "Makefile", delete "-I ~/snake/include -I ~/snake/ncursestw -L ~/snake/lib" in FLAGS.
     Note: in order to run this game in standard course server, we always need to install a curses.h library to compile. Then there is no need to modify anything.
  3. Run "$ make main" to compile.
  4. Run "$ ./main" to execute the game.
  
