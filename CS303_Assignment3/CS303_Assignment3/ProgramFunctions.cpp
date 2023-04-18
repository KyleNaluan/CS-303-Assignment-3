#include "ProgramFunctions.h"

#include <iostream>

using namespace std;

char displayMainMenu() {
	char choice;

	// Display Menu
	cout << "Program Menu Options:" << endl;
	cout << "   1 - Convert infix expression to postfix" << endl;
	cout << "   2 - Test Queue" << endl;
	cout << "   Q - Quit Program" << endl << endl;

	cout << "Select an Option: ";

	// Get choice
	cin >> choice;
	choice = toupper(choice);

	// Check validity of input and re-prompt user until valid
	while (choice != '1' && choice != '2' && choice != 'Q') {
		cout << endl;
		cout << "Invalid Choice. Please enter another option: ";
		cin.ignore(100, '\n');
		cin >> choice;
		choice = toupper(choice);
	}

	cout << endl;

	return choice;
}

char displayQueueMenu() {
	char choice;

	// Display menu
	cout << "Queue Menu Options:" << endl;
	cout << "   1 - Push an item to the back" << endl;
	cout << "   2 - Pop item from the front" << endl;
	cout << "   3 - Check item from the front" << endl;
	cout << "   4 - Check empty" << endl;
	cout << "   5 - Check size of queue" << endl;

	cout << "   Q - Quit program" << endl << endl;

	cout << "Select an Option: ";

	// Get choice
	cin >> choice;
	choice = toupper(choice);

	// Check validity of input and re-prompt user until valid
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' &&  choice != 'Q') {
		cout << endl;
		cout << "Invalid Choice. Please enter another option: ";
		cin.ignore(100, '\n');
		cin >> choice;
		choice = toupper(choice);
	}

	cout << endl;

	return choice;
}

void runPush(Queue<int>& q) {
	cout << "Enter a number to push to the back of the queue: ";
	int num = getIntegerInput();

	q.push(num);
}

void runPop(Queue<int>& q) {
	if (q.empty())
		cout << "Cannot remove item, queue is empty." << endl;
	else
		cout << "Successfully removed " << q.pop() << " from the front of the queue!" << endl;
}

void runFront(Queue<int>& q) {
	if (q.empty())
		cout << "Queue is empty." << endl;
	else
		cout << q.front() << " is at the front of the queue." << endl;
}

void runEmpty(Queue<int>& q) {
	if (q.empty())
		cout << "The queue is empty\n\n\n";
	else
		cout << "The queue is not empty\n\n\n";
}

void runExpressionManager(ExpressionManager eM) {
	string infix;
	bool keepRunning = true;

	while (keepRunning) {
		// Get infix from user input
		cout << "Please enter an infix expression: ";
		getline(cin, infix);

		// Check if balanced | if so, convert to postfix
		if (eM.is_balanced(infix)) {
			try {
				string post = eM.convert(infix);
				cout << "Postfix Expression: " << post << endl << endl;
			}
			catch (invalid_argument& e) {
				cout << "Invalid Argument: " << e.what() << endl << endl;
			}
		}
		else
			cout << "Expression not balanced" << endl << endl;

		// Ask user if they want to enter another expression
		char choice;
		cout << "Would you like to use the Infix to Postfix converter again? (Y/N)? ";
		cin >> choice;
		choice = toupper(choice);

		while (choice != 'Y' && choice != 'N') {
			cout << endl;
			cout << "Invalid Choice. Please enter another option: ";
			cin.ignore(100, '\n');
			cin >> choice;
			choice = toupper(choice);
		}

		cin.ignore(100, '\n');
		cout << endl;

		// End loop if user says no
		if (choice == 'N') {
			keepRunning = false;
		}
	}
}

int getIntegerInput() {
	int num;
	bool valid = false;

	// Keep asking user for input until valid input is received
	while (!valid) {
		try {
			cin >> num;
			cout << endl;

			// Logic from CS201L
			if (cin.fail()) {
				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				throw runtime_error("Invalid Input Received");
			}

			valid = true;
		}

		// If user enters non-integer value, then proceed to next iteration of the loop
		catch (runtime_error& e) {
			cout << e.what() << endl;
			cout << "Enter another number: ";
			continue;
		}

		// If any unknown errors occur, terminate the program
		catch (...) {
			cout << "Undefined error caught";
			abort();
		}
	}

	return num;
}

void runQueueMenu() {
	// Initialize Queue
	Queue<int> nums;

	// Run Menu Options
	bool keeprunning = true;
	char choice;

	cout << "Welcome to the Queue Menu!\n\n\n";

	while (keeprunning) {
		// Display Current Queue
		cout << "Current Queue:" << endl;
		nums.displayQueue();
		cout << endl;

		// Display Menu and Get Choice
		choice = displayQueueMenu();
		cin.ignore(100, '\n');

		// Run Functions based on user choice
		switch (choice) {
		case '1':
			runPush(nums);
			cout << endl << endl;
			break;
		case '2':
			runPop(nums);
			cout << endl << endl;
			break;
		case '3':
			runFront(nums);
			cout << endl << endl;
			break;
		case '4':
			runEmpty(nums);
			break;
		case '5':
			cout << "There are currently " << nums.size() << " items in the queue." << endl << endl << endl;
			break;
		case 'Q':
			keeprunning = false;
			break;
		}
	}
}

void runProgram() {
	bool keeprunning = true;
	char choice;
	ExpressionManager eM;

	cout << "Welcome to the Assignment 3!\n\n\n";

	while (keeprunning) {

		// Display Menu and Get Choice
		choice = displayMainMenu();
		cin.ignore(100, '\n');

		// Run Functions based on user choice
		switch (choice) {
		case '1':
			runExpressionManager(eM);
			break;
		case '2':
			runQueueMenu();
			break;
		case 'Q':
			keeprunning = false;
			break;
		}
	}

}
