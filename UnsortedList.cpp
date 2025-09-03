#include "UnsortedList.h"

template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    head = nullptr;
    currPos = nullptr;
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
        Node *testNode = new Node(); // tyr to make a test node
    } catch (std::bad_alloc &e) { // we're good ... delete the test node
        return true;
    }

    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return 0;
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
void UnsortedList<T>::DeleteItem(T item) {
    Node* currN = head;
    Node* prevN = nullptr;

    while (currN != nullptr) {
        if (currN->value == item) {
            if (prevN != nullptr) {
                // handle middle case
                prevN->next = currN->next;
            }
            else {
                head = currN->next;
            }
            delete currN;
            --length;
            return;
        }
        currN = currN->next;
    }



}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currPos = head;

}

template<class T>
T UnsortedList<T>::GetNextItem() {

}

template<class T>
void UnsortedList<T>::AddItem(T item) {
    Node *insertedNode = new Node;
    insertedNode->value = item;
    insertedNode->next = head;

    head = insertedNode;
    length++;
}