#include "UnsortedList.h"

template<class T>
UnsortedList<T>::UnsortedList() {
    // initialize variables
    length = 0;
    head = nullptr;
    currPos = nullptr;
}

template<class T>
UnsortedList<T>::~UnsortedList() {
    MakeEmpty();
}

template<class T>
void UnsortedList<T>::MakeEmpty() {
    length = 0;
    while (head!= nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    try {
        Node *testNode = new Node(); // try to make a test node
        delete testNode;             // we're good, delete the test node
    } catch (std::bad_alloc &e) {    // bad allocation it is out of memory
        return true;
    }

    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    Node* currN = head;
    while (currN != nullptr) {
        if (currN->value == someItem) {
            return true;
        }
        currN = currN->next;
    }
    return false;
}

template<class T>
void UnsortedList<T>::AddItem(T item) {
    Node *insertedNode = new Node;  // Create a new node
    insertedNode->value = item;     // Update new node value & immediately initialize it
    insertedNode->next = head;      // New node's next points to head
    head = insertedNode;            // Inserted node now points to head
    ++length;
}

// *** REMEMBER BEEM: Begin End Empty Middle
template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    Node* currN = head;
    Node* prevN = nullptr;  // no previous at this point

    while (currN != nullptr) {
        if (currN->value == item) {
            if (prevN != nullptr) {
                // handle middle case
                prevN->next = currN->next;
            } else {
                // handle beginning
                head = currN->next;
            }
            delete currN;
            --length;
            return;
        }
        prevN = currN;
        currN = currN->next;
    }
}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currPos = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {
    T currVal = currPos->value;
    currPos = currPos->next;
    return currPos->value;
}

