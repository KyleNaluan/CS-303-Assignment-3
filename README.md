# CS-303-Assignment-3
- Kyle Naluan

- This file outputs to the console
- Main only has a runProgram() function, which can be found in ProgramFunctions.h/.cpp

** Expression Manager and Queue Problems Implemented Separately **

- All expression manager functions can be found in ExpressionManager.h/.cpp

- Separate in this program is a Queue class, which I implemented using std::list as a container. I made Queue a template class so it could be made with any data type, so
  the function declarations and definitions are both in the .h file
  - This is because template classes cannot be compiled separately, implementing the functions in a .cpp would give a linker error
  - A work around would be instantiating the class in the .cpp, but the program would be limited to the item types that were instantiated
  
- Functions for the program functionality and declared in ProgramFunctions.h and defined in ProgramFunctions.cpp
  - These functions' primary purpose is to connect the expression manager and queue functions to the user menu
  
- This program starts by opening a main menu to the user with 3 options:

  - Convert infix expression to postfix
    - This function handles input for an expression
    - It checks if the parentheses are balanced, then converts the expression to postfix if they are
    - Displays postfix expression to user
    
  - Test Queue (For the purposes of this program I instantiated the queue using type int)
    - This function brings up another menu that provides the user option to try the queue functions
    - Last option is to quit the linked list menu, returning the user back to the main menu
 
  - Quit
     - This option exits the program
  
- Both menus loop until user decides to quit them

------------------------------------------------------------------------------------------------------

Screenshots:

- Main Menu
