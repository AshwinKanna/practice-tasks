
#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <iostream>
#include <assert.h>
#include "listNode.hpp"

using std::cout;
using std::endl;

template < class nodeType >
class linkedList {
    public:
        linkedList();
        ~linkedList();
        void insertAtStart(const nodeType &value);
        void insertAtEnd(const nodeType &value);
        bool isEmpty() const;
        void displayElements() const;
        int displayCount() const {
            return nodeCount;
        }
    private:
        int nodeCount;
        node<nodeType> *frontPtr;
        node<nodeType> *createNode(const nodeType &value);
};

template < class nodeType >
linkedList<nodeType>::linkedList() : frontPtr(nullptr), nodeCount(0) {}

template < class nodeType >
linkedList<nodeType>::~linkedList() {
    if(!isEmpty()) {
        node<nodeType> *iterPtr = frontPtr, *tmpPtr;

        while(iterPtr != nullptr) {
            tmpPtr = iterPtr;
            iterPtr = iterPtr->nextPtr;
            delete(tmpPtr);
        }
    }
}


template < class nodeType >
node<nodeType> *linkedList<nodeType>::createNode(const nodeType &value) {
    node<nodeType> *newNode = new node<nodeType>(value);
    assert(newNode != nullptr);
    return newNode;
}

template < class nodeType >
bool linkedList<nodeType>::isEmpty() const {
    if(frontPtr == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

template < class nodeType >
void linkedList<nodeType>::insertAtStart(const nodeType &value) {
    node<nodeType> *newNode = createNode(value);

    if(isEmpty()) {
        frontPtr = newNode;
    }
    else {
        newNode->nextPtr = frontPtr;
        frontPtr = newNode;
    }
    nodeCount++;
}

template < class nodeType >
void linkedList<nodeType>::insertAtEnd(const nodeType &value) {
    node<nodeType> *newNode = createNode(value);

    if(isEmpty()) {
        frontPtr = newNode;
    }
    else {
        node<nodeType> *tmpPtr = frontPtr;

        while(tmpPtr->nextPtr != nullptr) {
            tmpPtr = tmpPtr->nextPtr;
        }

        tmpPtr->nextPtr = newNode;
    }
    nodeCount++;
}

template < class nodeType >
void linkedList<nodeType>::displayElements() const {
    if(isEmpty()) {
        cout << "No elements in the list" << endl;
        return;
    }
    node<nodeType> *tmpPtr = frontPtr;
    int tmpCount = 1;
    while(tmpPtr != nullptr) {
        cout << "Element - " << tmpCount << " : " << tmpPtr->value << endl;
        tmpCount++;
        tmpPtr = tmpPtr->nextPtr;
    }
}

#endif
