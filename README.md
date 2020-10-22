# hkucs_project
**Proposal**

Group number: Group 72
 
Team member: 
Wu Anzhi 3035718840
Yang Guo 3035637670

Name of game: **Snake**
 
Game description:
Snake is a game where players can manipulate a line in a limited area. The line can move in four directions and touch the target objects to get longer. The longer the line, the higher grades the player can get. If the line hit the edges, itself or the bricks, the game over.
 
Basic rules:
A closed space surrounded by four walls
The line can move in four directions -- upward, downward, rightward, leftward
The line can become longer if its head touches the target points
The target points will appear randomly and last for a limited time before disappearance
The line can only move within the closed area
If head of the line hit the walls or its body, game over
 
Features:
1. Generation of random game sets or events
The target points appear randomly.
The target points have random duration.
The bricks appear randomly.

2. Data structures for storing game status
Array: used to store the basic length of the snake, positions of walls, random bricks, the direction of the snakes, position and duration of food, Game Duration, scores
Queue: used to store the movement of the snake
 
3. Dynamic memory management
store the direction of the snakes, position and duration of food, Game Duration, scores

4. File input/output (e.g., for loading/saving game status)
