#pragma once

#include <stack>
#include <string>

using namespace std;

class ExpressionManager {
private:
	// Infix to Postfix Data Fields
	stack<char> operator_stack;
	static const string OPERATORS;

	string postfix;

	// Balanced Parentheses Data Fields
	static const string OPEN;
	static const string CLOSE;

	// Private Infix to Postfix Functions
	void process_operator(char op);
	bool is_operator(char ch) const;

	// Private Balanced Parentheses Functions
	bool is_open(char ch);
	bool is_close(char ch);
	bool are_matching(char openP, char closeP);

public:
	// Default Constructor
	ExpressionManager();

	// Infix to Postfix
	string convert(const string& expression);

	// Balanced Parentheses
	bool is_balanced(const string& expression);
	int precedence(char op) const;

};