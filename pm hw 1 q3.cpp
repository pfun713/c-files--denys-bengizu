/* pm2 hw.cpp : This file contains the 'main' function. Program execution begins and ends there.
 db1039, Denys Bengizu
 I could not finish this, it was a bit confusing :( basically the last part of this question I could not do, not enough time for figuring this out together with all of my other
 classes I have to study for... put a lot of time into this homework that I am falling behind in other courses, I will attempt question 4 but probably wont be successful in it
 ****Special thanks to youtube channel knowledgeHighway and the textbook***
 Date Started: 09/ 22/ 2018
 Date Submitted: 09/23/2018
*/
#include "pch.h"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;



class No_index_Exception : public std::runtime_error {
public:
	// constructor specifies default error message
	No_index_Exception()
		:std::runtime_error{ "Value does not exist " } {}
};

template<typename Type> class List;

template<typename Type>
class ListNode {
	friend class List<Type>; // make List a friend

private:
	Type data; // data type
	int index;
	ListNode<Type>* nextPtr; // Move onto next listed number
public:
	explicit ListNode(const Type& info)
		: data{ info }, nextPtr{ nullptr } {}

	Type getData() const { return data; } // data is being returned in the node
};

class Exception_Empty : public std::runtime_error {
public:
	// constructor specifies default error message
	Exception_Empty()
		:std::runtime_error{ "Attempt for popping or dequeing from an empty list " } {}
};

template<typename TYPEDEC>
class List {
public:
	// destructor
	~List() {
		if (!isEmpty()) { // List is not empty
			std::cout << "Nodes deleting \n";

			ListNode<TYPEDEC>* currentPtr{ firstPtr };
			ListNode<TYPEDEC>* tPtr{ nullptr };

			while (currentPtr != nullptr) { // delete remaining nodes
				tPtr = currentPtr;
				std::cout << tPtr->data << '\n';
				currentPtr = currentPtr->nextPtr;
				delete tPtr;
			}
		}

		std::cout << "All nodes destroyed\n\n";
	}

	

	// insert node at back of list
	void Enqueue(const TYPEDEC& value) {
		ListNode<TYPEDEC>* newPtr{ getNewNode(value) }; // new node

		if (isEmpty()) { // List is empty
			firstPtr = lastPtr = newPtr; // new list has only one node
			newPtr->index = 0;
		}
		else { // List is not empty
			int tempIndex = lastPtr->index;
			lastPtr->nextPtr = newPtr; // update previous last node
			lastPtr = newPtr; // new last node
			newPtr->index = tempIndex + 1;
		}
	}

	// delete node from front of list
	const Type& Pop() {
		TYPEDEC value;
		ListNode<TYPEDEC>* tempPtr{ firstPtr }; // grabs info for future deletion 

		if (firstPtr == lastPtr) {
			firstPtr = lastPtr = nullptr; // All nodes removed
		}
		else {
			firstPtr = firstPtr->nextPtr; // point to previous 2nd node
			ListNode<TYPEDEC>* tPtr2 = firstPtr;
			while (tPtr2 != nullptr) {
				tPtr2->index = tPtr2->index - 1;
				tPtr2 = tPtr2->nextPtr;
			}
		}

		value = tPtr->data; // return data being removed
		delete tempPtr; // reclaim previous front node
		return value; // delete successful
	}

	// delete node from back of list

	const TYPEDEC& Dequeue() {
		TYPEDEC value;
		ListNode<TYPEDEC>* tempPtr{ lastPtr }; // hold item to delete

		if (firstPtr == lastPtr) { // List has one element
			firstPtr = lastPtr = nullptr; // no nodes remain after removal
		}
		else {
			ListNode<TYPEDEC>* currentPtr{ firstPtr };

			// locate second-to-last element
			while (currentPtr->nextPtr != lastPtr) {
				currentPtr = currentPtr->nextPtr; // move to next node
			}

			lastPtr = currentPtr; // remove last node
			currentPtr->nextPtr = nullptr; // this is now the last node
		}

		value = tempPtr->data; // return value from old last node
		delete tempPtr; // reclaim former last node
		return value; // delete successful
	}

	// checking if list is empty

	bool isEmpty() const {
		return firstPtr == nullptr;
	}
	// all of this in the next set of braces will be a bunch of pointers that will help me in my later code for traverse
	const TYPEDEC& Traverse(int index) {
		TYPEDEC value;
		ListNode<TYPEDEC>* TemporaryPointer{ firstPtr };
		ListNode<TYPEDEC>* currentPtr{ TemporaryPointer };

		while (TemporaryPointer != nullptr && TemporaryPointer->index != index) {
			currentPtr = TemporaryPointer;
			TemporaryPointer = TemporaryPointer->nextPtr;
		}

		if (TemporaryPointer == nullptr) {// case when there is no matching index
			throw No_index_Exception{};
		}

		if (TemporaryPointer == firstPtr) {// case when retrieving an item from the front
			return Pop();
		}
		if (TemporaryPointer == lastPtr) {// case when retrieving an item from the back
			return Dequeue();
		}

		value = TemporaryPointer->data;
		currentPtr->nextPtr = TemporaryPointer->nextPtr;
		delete TemporaryPointer;

		TemporaryPointer = currentPtr->nextPtr;

		while (TemporaryPointer != nullptr) {
			TemporaryPointer->index = TemporaryPointer->index - 1;
			TemporaryPointer = TemporaryPointer->nextPtr;
		}

		return value;
	}

	// insert node at front of list
	void Push(const TYPEDEC& value) {
		ListNode<TYPEDEC>* newPtr{ getNewNode(value) }; // new node

		if (isEmpty()) { // List is empty
			firstPtr = lastPtr = newPtr; // new list has only one node
			newPtr->index = 0;
		}
		else { // List is not empty
			newPtr->nextPtr = firstPtr; // point new node to old 1st node
			firstPtr = newPtr; // aim firstPtr at new node
			newPtr->index = 0;
			ListNode<TYPEDEC>* tempPtr = newPtr->nextPtr;
			while (tempPtr != nullptr) {
				tempPtr->index = tempPtr->index + 1;
				tempPtr = tempPtr->nextPtr;
			}
		}
	}

	// display contents of List
	void print() const {
		if (isEmpty()) { // List is empty
			std::cout << "Empty list here. \n";
			return;
		}

		ListNode<TYPEDEC>* currentPtr{ firstPtr };

		std::cout << "Here is the list: ";

		while (currentPtr != nullptr) { // each elements data is fetched
			std::cout << currentPtr->data << ' '; // pointers to data 
			currentPtr = currentPtr->nextPtr;
		}

		std::cout << "\n\n";
	}
	const NODETYPE& peek() {
		return firstPtr->data;
	}



	const TYPE& peek() {
		return pos1track->data;
	}



	void swap(ListNode<TYPE>* P1Last, ListNode<TYPE>* currentIndex) {

		if (P1Last == pos1track && currentIndex == p1Last) {
			P1Last->P1Last = currentIndex; currentIndex->NextLocation = P1Last; currentIndex->P1Last = nullptr; P1Last->NextLocation = nullptr;
			int tempIndex = P1Last->index; P1Last->index = currentIndex->index; currentIndex->index = tempIndex; pos1track = currentIndex;
			p1Last = P1Last;
			std::cout << "swapped Node " << currentIndex->index << " with Node " << P1Last->index << "\n"; // this works most of the time... sorry :( hopefully it works for allt he tests you run
			return;
		}

		if (P1Last == pos1track) {
			ListNode<TYPE>* Tp1 = currentIndex->NextLocation;
			currentIndex->NextLocation = P1Last; currentIndex->P1Last = nullptr; P1Last->NextLocation = Tp1; P1Last->P1Last = currentIndex;
			Tp1->P1Last = P1Last; int tempIndex = P1Last->index; P1Last->index = currentIndex->index;
			currentIndex->index = tempIndex; pos1track = currentIndex;
			std::cout << "swapped Node " << currentIndex->index << " with Node " << P1Last->index << "\n";
			return;
		}
		if (currentIndex == p1Last) {
			ListNode<TYPE>* Tp1 = P1Last->P1Last; currentIndex->NextLocation = P1Last;
			currentIndex->P1Last = Tp1; Tp1->NextLocation = currentIndex; P1Last->NextLocation = nullptr; P1Last->P1Last = currentIndex;
			int tempIndex = P1Last->index; P1Last->index = currentIndex->index;
			currentIndex->index = tempIndex; p1Last = P1Last;
			std::cout << "swapped Node " << currentIndex->index << " with Node " << P1Last->index << "\n";
			return;
		}

		if (P1Last != pos1track && currentIndex != p1Last) {
			ListNode<TYPE>* Tp1 = P1Last->P1Last;
			P1Last->NextLocation = currentIndex->NextLocation; P1Last->P1Last = currentIndex; currentIndex->NextLocation->P1Last = P1Last;
			currentIndex->NextLocation = P1Last; currentIndex->P1Last = Tp1; Tp1->NextLocation = currentIndex;
			int temIndex = P1Last->index;
			P1Last->index = currentIndex->index; currentIndex->index = temIndex;
			std::cout << "swapped Node " << currentIndex->index << " with Node " << P1Last->index << "\n";return;
		}
	}



	void InsertionSort() {
		if (pos1track == p1Last) {
			print();
			std::cout << "No sorting performed.\n";
			return;
		}
		ListNode<TYPE>* P1Last = pos1track;
		ListNode<TYPE>* currentIndex = pos1track->NextLocation;
		while (currentIndex != nullptr) {
			ListNode<TYPE>* temPtr = currentIndex->NextLocation;// used to mark the insert node for next iteration
			TYPE insert = currentIndex->data;

			while (P1Last->data > insert) {

				swap(P1Last, currentIndex); // Now P1Last becomes currentIndex & currentIndex becomes P1Last
				P1Last = currentIndex->P1Last;// compare all nodes before insert node to insert node
				print();
				if (P1Last == nullptr) {
					break;// because the P1Last of pos1track is nullptr, avoid this case
				}
			}
			currentIndex = temPtr; // make next node an insert node
			if (temPtr != nullptr) {// avoid the case when temPtr becomes a nullptr
				P1Last = temPtr->P1Last; // if temPtr is a nullptr, then currentIndex in this iteration is p1Last
			}
		}
		std::cout << "Sort Finished\n";
		return;
	}

private:
	ListNode<TYPE>* pos1track{ nullptr }; // pointer to first node
	ListNode<TYPE>* p1Last{ nullptr }; // pointer to last node

	// utility function to allocate new node
	ListNode<TYPE>* getNewNode(const TYPE& value) {
		return new ListNode<TYPE>{ value };
	}

};



void InsertionSort() {
	if (firstPtr == lastPtr) {
		print();
		std::cout << "No sorting performed.\n";
		return;
	}
	ListNode<TYPE>* LASTPtr = firstPtr;
	ListNode<TYPE>* currentPtr = firstPtr->nextPtr;
	while (currentPtr != nullptr) {
		ListNode<TYPE>* temPtr = currentPtr->nextPtr;// used to mark the insert node for next iteration
		TYPE insert = currentPtr->data;

		while (LASTPtr->data > insert) {

			swap(LASTPtr, currentPtr); // Now LASTPtr becomes currentPtr & currentPtr becomes LASTPtr
			LASTPtr = currentPtr->LastPtr;// compare all nodes before insert node to insert node
			print();
			if (LASTPtr == nullptr) {
				break;// because the LastPtr of firstPtr is nullptr, avoid this case
			}
		}
		currentPtr = temPtr; // make next node an insert node
		if (temPtr != nullptr) {// avoid the case when temPtr becomes a nullptr
			LASTPtr = temPtr->LastPtr; // if temPtr is a nullptr, then currentPtr in this iteration is lastPtr
		}
	}
	std::cout << "Sort Finished\n";
	return;
}

private:
	ListNode<TYPE>* firstPtr{ nullptr }; // pointer to first node
	ListNode<TYPE>* lastPtr{ nullptr }; // pointer to last node

	// utility function to allocate new node
	ListNode<TYPE>* getNewNode(const TYPE& value) {
		return new ListNode<TYPE>{ value };
	}

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
				try {
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
					cout << listObject.Dequeue() << " removed from list\n";
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

	cout << "End list test\n\n";
}

// and finally the main function and we are done with this problem :D
int main() {
	List<int> intList;
	testList(intList, "integer");
}
#include "pch.h"
