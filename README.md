# Battleship game

![alt text](https://img.shields.io/badge/License-GPL%20v3-blue.svg)
![alt text](https://img.shields.io/badge/Linux-CentOS-blue.svg) <br />

# Description

This is a two-player game in which each player has to initially place his ships in his personal 10x10 grid. The ships which are available to each player are 5 and more specifically, a patrol boat with size 2, a destroyer with size 3, a submarine with size 3, a battleship with size 4 and an aircraft carrier with size 5. After the positioning of the ships, it is time for the main game stage which contains a series of rounds in each of which the one player tries to guess the possible coordinates of the other player’ s ships in order to shot them. Hence, either he hits a ship or it is a miss. Then, it is enemy’s responsibility to announce to the attacking player the result of his shot. This continuous process comes to an end when all of a player’s ships have been sunk and the program announces both that the game is over and the name of the winner (player 1 or player 2). <br />

# Gameplay instructions

During the “place ships” phase of the game both players decide where they want to place their ships according to this particular pattern: Facing (0: horizontal or 1: vertical) – press space - X - axis coordinate – press space - Y - axis coordinate. For example, if you type 0 4 3 this would place a ship beginning at X:4 Y:3 and going horizontal. During the main phase of the game, you have to type the attacking coordinates (X – axis, Y – axis) separated by a space. <br />

# My approach

I thought a program which contains one 10x10 grid per player (using arrays), the different kinds of ships available for positioning and also their predefined lengths (using appropriate function). Furthermore, the program can collect each player' s placements of it' s ships using two loops (players, ships). After these, the program alternate between each player (attacking – defending) using a while loop and receive each time a pair of coordinates to attack to each other, while it makes the necessary changes to the grids according to the shots (hit or miss). In order to make the program end when someone has been run out of ships, I thought to put a “game over” check inside the while loop. Finally, the program has the necessary information to announce the winner of the game. <br />

# Issues

The first problem I have had to deal with, was the necessity to reset the grid provided to the second player to be filled inside the two for loops. Then I created the appropriate reset() function which is invoked before the loops. Another issue I faced, had to do with cheating between the attacking and defending player while it was possible for the attacking player to see the defending' s grid before the attacking coordinates selection. I solved this problem by putting the command system(“clear”); and now the only way to cheat is to scroll up. Last but not least, after the code execution it was impossible to pause the results while the terminal was pushing the program to shut down. I solved that problem by invoking the command cin.ignore().get(); (which is the pause command for Linux terminal) at the end of the program and now the result of the game is visible even after code running. <br />

# Functions

In order my code to be more well-organised I used header files for each
of my functions. More specifically, function LoadShips() contains all the ships' names and their
lengths respectively. Function RESET() simply “clears” the grid (sets all the points as water)
letting the other player to put his own ships. Function SHOW(int,bool) is used to display
separately each player’s grid (I tried to enhance the whole process with the appropriate colors in
order to be similar to a typical game). Furthermore, using the boolean “gameRunning”, SHOW()
is combined with the function GameOverCheck(int) which is responsible for the game ending
checking every time if any ships remain. Additionally, inside the function InputShipPosition() I
use the constructor “PLACESHIPS tmp” (which uses two other constructors “DIRECTION
direction” and “SHIP shipType”) where I define “tmp.shipType.onGrid[0].X = -1;” as a bad return,
then three integers are inserted (by the user) which are filtered according to the number of
rows and columns and finally we get the useful data. Now, it is time for the function
InputAttack(int&,int&,int) which receives the attacking coordinates (and checks them using a
new boolean “goodInput”). In that point, it is important to mention the importance of using
references in InputAttack(int&,int&,int), because otherwise there would be misunderstandings
from the main program about the int sequence (and that was an extra issue I initially faced). <br />

# Limitations

This game is strictly created for using 10x10 grids, for 2 players and it is mandatory
for each user to place all of his ships (this particular types). Also, the program does not provide
any check for placing one ship above one other, but a real-time grid is available to each player
(when he places his ships) in order to avoid this potential issue. Hence, each player has to place
his own ships using only the appropriate coordinates. <br />

In order to compile my code I used gcc compiler for Linux (Ubuntu) operating system and I invoked the
below command: <br />
g++ GameOverCheck.cpp InputAttack.cpp InputShipPosition.cpp MAIN.cpp RESET.cpp SHOW.cpp -o
MAIN <br />
<br />
and then in order to execute it, the command: <br />
./MAIN
