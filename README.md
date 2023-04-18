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
    - This function handles input for an infix expression
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
- ![image](https://user-images.githubusercontent.com/112575790/232672476-f20c9bba-7929-4f07-9cf2-fdc1e1884da3.png)

- Read Infix Expression + Non-balanced Parentheses
- ![image](https://user-images.githubusercontent.com/112575790/232672760-fcb8fbd3-0e02-4738-97be-38cfce6c6629.png)

- Read Infix Expression + Balanced Parentheses + Output Postfix Expression
- ![image](https://user-images.githubusercontent.com/112575790/232672982-b8777d70-1e89-4286-b85b-fcfd460c2906.png)

- Queue Menu
- ![image](https://user-images.githubusercontent.com/112575790/232673069-5475299c-1680-42b7-bfea-f563ef58fc19.png)

- Push
- ![image](https://user-images.githubusercontent.com/112575790/232673296-2386af37-1d7e-4507-807d-a131d065b6e8.png)

- Pop
- ![image](https://user-images.githubusercontent.com/112575790/232673360-21a88550-73ac-41a9-90df-fc91d4b83d01.png)

- Front
- ![image](https://user-images.githubusercontent.com/112575790/232673451-635238c8-05be-413f-a233-98802dd1d099.png)

- Empty
- ![image](https://user-images.githubusercontent.com/112575790/232673527-13771c58-74ea-4f35-bdd3-8397c8758a38.png)
- ![image](https://user-images.githubusercontent.com/112575790/232673617-28553317-c729-49e1-a9ca-09bb9a749a85.png)

- Size
- ![image](https://user-images.githubusercontent.com/112575790/232673576-4154dc05-3f21-42ae-a244-8bb80b852383.png)







