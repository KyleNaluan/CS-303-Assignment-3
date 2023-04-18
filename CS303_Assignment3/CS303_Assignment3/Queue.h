#pragma once

#include <iostream>
#include <list>

using namespace std;

template <typename T>
class Queue {
private:
	list<T> container;

public:
	// Inserts an element at the end of the queue
	void push(const T& item) {
		container.push_back(item);
	}

	// Removes the front element of the queue and returns it
	T pop() {
		T front = container.front();
		container.pop_front();
		return front;
	}

	// Returns the front element of the queue without removing it
	T front() {
		return container.front();
	}

	// Checks if the queue is empty
	bool empty() const {
		return container.empty();
	}

	// Returns the total number of elements present in the queue
	size_t size() const {
		return container.size();
	}

	// Displays the queue
	void displayQueue() {

		for (auto it = container.begin(); it != container.end(); ++it) {
			cout << *it << " ";
		}

		cout << endl;
	}

};