# COMP2113_Group Project
## **Proposal**

Group number: **Group 72**
 
Team member: 
**Wu Anzhi 3035718840**
**Yang Guo 3035637670**

Name of game: **Snake**
 
Game description:
* This is a console program.
* **Snake** is a game where players can manipulate a "snake" (consisting of strings) in "map" (a limited area). 
* The "snake" can move in four directions and get "food" to get longer. 
* The longer the "snake", the higher scores the player can get. 
* If the "snake" hit the edges, itself or the bricks, game over.
 
Basic rules:
* A closed space surrounded by four walls
* The "snake" can move in four directions -- upward, downward, rightward, leftward.
* The "snake" can become longer if its head touches "food" (the target points).
* The "food" will appear randomly.
* The "snake" can only move within "map".
* If head of the "snake" hit the walls, its body or bricks, game over.
 
Features:
1. Generation of random game sets or events
* The target points appear randomly
* The bricks appear randomly

2. Data structures for storing game status
* Array: used to store 
  - the basic length of the snake
  - positions of walls
  - random bricks
  - the direction of the snakes
  - position and duration of food
  - Game Duration
  - scores
* Queue: used to store 
  - the movement of the snake
 
3. Dynamic memory management
* store: 
  - direction of the snakes
  - position and duration of food
  - Game Duration
  - scores

4. File input/output (e.g., for loading/saving game status)
* Loading/Saving: 
  - position of the snake
  - position and duration of the food
  - position of the bricks, scores
  - game duration
  - highest scores
 
5. Program codes in multiple files
* We divide the game into many small parts

  - Main: 
    * To run the game
 
  - Controller: 
    * Monitor keyboard (<↑><↓><←><→> for change selection/ <ESC> to open the menu/ <Enter> for choice and others)
    * Initialize game interface (Start new game/ Load game/ Exit)
    * Menu (Pause the game/ Save/ Save and Exit/ Restart)
    * Print Highest Score & Game Duration
    * End-game animation (Game over →Restart?)
 
   - Food: 
     * Randomly generate food
     * Randomly defined the duration of food
 
   - Map: 
     * Initialize every point in the map. E.g. “■” means the wall
 
   - Snake: 
     * Length (Current length/ increase length [eat food])
     * Gameover (run into wall, brick, self)
     * Direction (<↑><↓><←><→> )
 
   - Interface: 
     * begin-game animation
     * window size
