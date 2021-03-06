/* pm2 hw.cpp : This file contains the 'main' function. Program execution begins and ends there.
 db1039, Denys Bengizu
 question 1 hw 2... sorry again that I have it all in one file, this one was not too bad since we use almost the same code as we do in problem 1...
 I honestly used this problem to help guide me on how to do problem 1... it was pretty bad, youtube videos and textbook examples is what I had to do to understand
 what I had to do on this homework... I do not think that a lot of people can do these problems that were assigned... it was a bit too hard :( if I were given this
 on an exam with no resource and with a finite time, I would fail, I have to thank youtube for helping me out in refreshing c++ and learning some more... templates
 and node declaration especially(please go over what you mean by node) I am just inserting it where I think it belongs without being 100% sure, as long as the code
 ran I was happy and called it a day.
 Date Started: 09/ 20/ 2018
 Date Submitted: 09/22/2018
*/

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;


template<typename NODEVARIABLEDEC>
class QueueArray {
public:
	QueueArray(int capacity) {
		firstPtr = new NODEVARIABLEDEC[capacity]{};
		capac = capacity;
	}

	bool isEmpty() {
		return n == 0;
	}

	void Enqueue(const NODEVARIABLEDEC& item) {
		if (n < capac) { firstPtr[n++] = item;return; }
		if (n == capac) {
			NODEVARIABLEDEC* temPtr = new NODEVARIABLEDEC[2 * capac]{};
			for (int i = 0; i < n; i++) {
				temPtr[i] = firstPtr[i];
			}
			temPtr[n] = item;
			capac = 2 * capac;
			n = n + 1;
			delete[] firstPtr;
			firstPtr = temPtr;
			return;
		}
	}
	const NODEVARIABLEDEC& Dequeue() {

		return firstPtr[--n];

	}

	void Push(const NODEVARIABLEDEC& item) {
		if (n < capac) {
			for (int i = n; i >= 1; i--) {
				firstPtr[i] = firstPtr[i - 1];
			}
			firstPtr[0] = item;
			n = n + 1;
			return;
		}
		if (n == capac) {
			NODEVARIABLEDEC* temPtr = new NODEVARIABLEDEC[2 * capac]{};
			for (int i = 0; i < n; i++) {
				temPtr[i + 1] = firstPtr[i];
			}
			temPtr[0] = item;
			capac = 2 * capac;
			n = n + 1;
			delete[] firstPtr;
			firstPtr = temPtr;
			return;
		}
	}
	const NODEVARIABLEDEC& Pop() {
		NODEVARIABLEDEC item;
		NODEVARIABLEDEC* temPtr = new NODEVARIABLEDEC[capac - 1]{};
		for (int i = 0; i < capac - 1; i++) {
			temPtr[i] = firstPtr[i + 1];
		}
		item = firstPtr[0];
		capac = capac - 1;
		n = n - 1;
		delete[] firstPtr;
		firstPtr = temPtr;
		return item;
	}

	const NODEVARIABLEDEC& Traverse(int index) {
		NODEVARIABLEDEC item;
		if (index >= n) {
			throw NoindexException{};
		}
		if (index == 0) {
			return Pop();
		}
		if (index == n - 1) {
			return Dequeue();
		}
		item = firstPtr[index];
		for (int i = index; i < n - 1; i++) {
			firstPtr[index] = firstPtr[index + 1];
		}
		--n;
		return item;
	}

	void print()
	{
		if (isEmpty()) { // Array is empty
			cout << "The Array is empty\n\n";
			return;
		}
		cout << "The array is: ";
		for (int i = 0; i < n; i++) {
			cout << firstPtr[i] << " ";
		}
		cout << "\n\n";
		return;
	}
private:
	NODEVARIABLEDEC* firstPtr{ nullptr };
	int n = 0;//  number of elements
	int cap = 0;
};


class EmptyException : public std::runtime_error {
public:
	// constructor specifies default error message
	EmptyException()
		: std::runtime_error{ "attempted to Pop or Dequeue from empty array" } {}
};





// Below is the instructions that will be displayed at each point later on in my code where I call this function
void instructions() {
	cout << "Enter any of the following numbers to do the accomponied execution: \n"
		<< "  1 to insert at beginning of list \n"
		<< "  2 to insert at end of list \n"
		<< "  3 to delete from beginning of list \n"
		<< "  4 to delete from end of list \n"
		<< "  5 to retrieve an item from list \n"
		<< "  6 to end list processing \n";
}

// Below is the List testing function
template<typename T>
void testList(List<T>& listObject, const string& typeName) {
	cout << "Testing a list of " << typeName << " values\n";
	instructions(); //  at this point the instructions will be displayed

	int choice; // grab users input
	T value; // hold the user input

	// now we use a loop with user interactions
	do {
		cout << "? ";
		if (cin >> choice) { // grabs the users choice for choosing the appropriate case as listed below

			switch (choice) {
			case 1: // Here we start grabbing inputs for the list
				cout << "Enter " << typeName << ": ";
				cin >> value;
				listObject.Push(value);
				listObject.print();
				break;
			case 2: // inserts a value at the end
				cout << "Enter " << typeName << ": ";
				cin >> value;
				listObject.Enqueue(value);
				listObject.print();
				break;
			case 3: // remove from the beginning of a list
				try { // Thank you textbook!!!!!!!! this really helped
					if (listObject.isEmpty() == 1) {
						throw Exception_Empty{};
					}
					cout << listObject.Pop() << " removed from list\n";
				}
				catch (const Exception_Empty& Exception_Empty) {
					cout << "Exception occurred: "
						<< Exception_Empty.what() << endl;
				}
				listObject.print();
				break;
			case 4: // Removes from the end of a list
				try {
					if (listObject.isEmpty() == 1) {
						throw Exception_Empty{};
					}
					cout << listObject.Dequeue() << " removed from list \n";
				}
				catch (const Exception_Empty& Exception_Empty) {
					cout << "Exception occurred: "
						<< Exception_Empty.what() << endl;
				}
				listObject.print();
				break;
			case 5:// does the traverse operation.. aka retrieves an index value 
				int index;
				cout << "Enter index you want to retrieve: ";
				cin >> index;
				try {
					if (listObject.isEmpty() == 1) {
						throw Exception_Empty{};
					}
					try { value = listObject.Traverse(index); }
					catch (const No_index_Exception& NoindexException) {
						cout << "Exception occurred: "
							<< NoindexException.what() << endl;
						listObject.print();
						break;
					}
					cout << value << " removed from list\n";
				}
				catch (const Exception_Empty& Exception_Empty) {
					cout << "Exception occurred: "
						<< Exception_Empty.what() << endl;
				}
				listObject.print();
				break;
			}
		}
		else { break; }
	} while (choice < 6);

	cout << "End of list test statement \n";
}

// and finally the main function and we are done with this problem :D
int main() {
	List<int> intList;
	testList(intList, "integer ");
}
#include "pch.h"