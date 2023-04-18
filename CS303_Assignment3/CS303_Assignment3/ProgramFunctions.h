#pragma once

#include "ExpressionManager.h"
#include "Queue.h"

/*

========== MENU FUNCTIONS ==========

*/

char displayMainMenu();
// post : displays a menu with three choices - convert infix to postix, use queue, and quit - then returns that users choice

char displayQueueMenu();
// post : displays a menu with choices corresponding to the queue functions, then returns the option the user chose

/*

========== LIST FUNCTIONS ==========

*/

void runPush(Queue<int>& q);
// post : asks user for an integer input and runs push() 

void runPop(Queue<int>& q);
// post : first checks if queue is empty, then runs the pop() function and displays a message to the user if successful + the item it removed

void runFront(Queue<int>& q);
// post : first checks if queue is empty, then runs the front() function and displays a message to the user with the first item in queue

void runEmpty(Queue<int>& q);
// post : runs the empty() function and displays a message to the user if the queue is empty or not

/*

========== EXPRESSION MANAGER FUNCTIONS ==========

*/

void runExpressionManager(ExpressionManager eM);
// post : Handles all functionalities of expression manager, including input, balanced parentheses, and postfix

/*

========== INPUT VERIFICATION ==========

*/

int getIntegerInput();
// post : gets user input for an integer, checks to see if a number was entered, then returns the int value

/*

========== PROGRAM FUNCTIONS ==========

*/

void runQueueMenu();
// post : handles the user input from displayQueueMenu() and runs a queue function depending on that input

void runProgram();
// post : runs the functionalities of the program