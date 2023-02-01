# Alien vs. Zombie

<img title="alien vs zombie" alt="program" src="/h/image.png">

Alien vs Zombie is a game that alien(user) will victory after defeating all the zombie. 
Before getting into the gmae, user have the chance to change the number of rows, columns and zombie.
Inside the game, user are free to move up, down, left or right by typing out the command.
User can plan their by ways by changing the direction of the arrow before being killed by the zombie.
To let the game more interesting, pod(cause damage to zombie), health(add Alien's health) 
and rock(gives out random object) will be added to the game.

Please provide the YouTube link to your [Video Demo](https://youtu.be/UxfT_eHzWsQ).

## Compilation Instructions

1.g++ -o main main.cpp amove.cpp attributes.cpp board.cpp csetting.cpp direction.cpp command.cpp help.cpp helper.cpp implementing.cpp
   OR
  g++ *.cpp -o main
  
2. .\main

## User Manual

1. Game setting:
- Enter 'y' if you want to change the game setting. 
- Enter the number of rows(odd number), number of columns(odd number) and number of zombies. 
- Enter any other than 'y' if you wish to use the default game setting.

2. Command of the game.
Enter ‘help’ to look for the command.
Giving an incorrext command, will also lead you to the command list

Command list: 
up     : Move up
down   : Move down
left   : Move left
right  : Move right
arrow  : Change direction of an arrow
help   : Display command list
save   : Save game           (still implementing)
load   : Load previous game  (still implementing)
quit   : Quit game

3. Game object:

Game object list:
Arrow   : ^(up), v(down), <(left), >(right)
Health  : h
Pod     : p
Rock    : r
Alien   : A
Zombie  : any integer

4. How to play:
- Enter up, down, left, right to control the movement of the Alien(A).
- When the Alien finds an arrow( ^, v, <, >), its attack will increase by 20.
- When the Alien hits the border, it will stop.
- When the Alien finds a new object(h, p, r) it will stop.
- Enter row, column and direction to change the direction of the arrow to the direction that you want.
- Enter quit to quit the game.

Please DO NOT change the Progress Log below. Leave it as it is.

## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

Please replace the following with your group members' names. 

- Chia Zhi Xuan
- Chin Wei Ling
- Sally Khor Zhi Xuan


