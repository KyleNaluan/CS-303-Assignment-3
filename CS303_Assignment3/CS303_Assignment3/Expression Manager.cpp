#include "ExpressionManager.h"
#include <iostream>
#include <sstream>

using namespace std;

const string ExpressionManager::OPERATORS = "+-*/%";
const string ExpressionManager::OPEN = "([{";
const string ExpressionManager::CLOSE = ")]}";

// Default Constructor
ExpressionManager::ExpressionManager() {
	postfix = "";
}


/** Function to process operators
	*/
void ExpressionManager::process_operator(char op) {
	if (operator_stack.empty()) {
		operator_stack.push(op);
	}
	else {
		if (precedence(op) > precedence(operator_stack.top()))
			operator_stack.push(op);
		else {
			// Pop all stacked operators with equal
			// or higher precedence than op.
			while (!operator_stack.empty() && (precedence(op) <= precedence(operator_stack.top()))) {
				postfix += operator_stack.top();
				postfix += " ";
				operator_stack.pop();
			}
			operator_stack.push(op);
		}
	}
}

/** Determines whether a character is an operator
	*/
bool ExpressionManager::is_operator(char ch) const{
	return (OPERATORS.find(ch) != string::npos);
}

/** Determines the precedence of an operator
	*/
int ExpressionManager::precedence(char op) const {
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/' || op == '%')
		return 2;
	else
		return -1;
}

/** Fuction to determine whether a character is one of the opening
	parentheses
	*/
bool ExpressionManager::is_open(char ch) {
	return (OPEN.find(ch) != string::npos);
}

/** Fuction to determine whether a character is one of the closing
	parentheses
	*/
bool ExpressionManager::is_close(char ch) {
	return (CLOSE.find(ch) != string::npos);
}

/** Function to determine if an opening and closing parentheses
	are matching
	*/
bool ExpressionManager::are_matching(char openP, char closeP) {
	if (openP == '(' && closeP == ')')
		return true;
	else if (openP == '{' && closeP == '}')
		return true;
	else if (openP == '[' && closeP == ']')
		return true;

	return false;
}


/** Extracts and processes each token in infix and returns the
	equivalent postfix string
	@param expression - the infix expression - must have a space between each character
	@return - The equivalent postfix expression
	*/
string ExpressionManager::convert(const string& expression) {
	postfix = "";
	
	// Clear operator stack before converting
	while (!operator_stack.empty()) {
		operator_stack.pop();
	}

	istringstream infix_tokens(expression);
	string next_token;

	// Loop through expression
	while (infix_tokens >> next_token) {
		if (isalnum(next_token[0])) {
			postfix += next_token;
			postfix += " ";
		}

		// Check for parentheses
		else if (is_open(next_token[0])) {
			operator_stack.push(next_token[0]);
		}

		else if (is_close(next_token[0])) {
			// Check if the parentheses are matching
			while (!operator_stack.empty() && !are_matching(operator_stack.top(), next_token[0])) {
				postfix += operator_stack.top();
				postfix += " ";
				operator_stack.pop();
			}
			operator_stack.pop();
		}

		// Now handle operators
		else if (is_operator(next_token[0])) {
			process_operator(next_token[0]);
		}

		else {
			throw invalid_argument("Unexpected Character Encountered");
		}
	}

	// Pop any remaining operators and append them to post fix
	while (!operator_stack.empty()) {
		char op = operator_stack.top();
		operator_stack.pop();
		postfix += op;
		postfix += " ";
	}

	return postfix;
}


/** Test the input string to see that it contains balanced parentheses.
	*/
bool ExpressionManager::is_balanced(const string& expression) {
	// A stack for the open parentheses that haven't been matched
	stack<char> s;
	bool balanced = true;
	string::const_iterator iter = expression.begin();
	while (balanced && (iter != expression.end())) {
		char next_ch = *iter;
		if (is_open(next_ch))
			s.push(next_ch);
		else if (is_close(next_ch)) {
			if (s.empty())
				balanced = false;
			else {
				char top_ch = s.top();
				s.pop();
				balanced = OPEN.find(top_ch) == CLOSE.find(next_ch);
			}
		}
		++iter;
	}
	return (balanced && s.empty());
}