// intlist.cpp
// Implements class IntList
// Michelle Ly, 04/28
//CITATION - lecture 6, cmpsc 24 spring 2021

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    first = nullptr;
    Node* n = source.first;
    while(n){
        int value = n->info;
        append(value);
        n = n->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    clear(first);
    first = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    if(first == NULL){
        return 0;
    }
    int sum = first->info; //needs to add first node's value before going to next node
    Node* curNode = first->next; //goes to next node
    while(curNode != NULL){
        sum += curNode->info;//iterates thru each node after first
        curNode = curNode->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    if(first == NULL){
        return false;
    }
    if(first->info == value){
        return true;
    }
    Node* curNode = first->next;
    while(curNode != NULL){
        if(curNode->info == value){
            return true;
        }
        curNode = curNode->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = 0;
    if(first == NULL){
        return 0;
    }
    if(first->info > max){
        max = first->info;
    }
    Node* curNode = first->next;
    while(curNode != NULL){
        if(curNode->info > max){
            max = curNode->info;
        }
        curNode = curNode->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int numNodes = 0;
    double sum = 0;
    if(first == NULL){
        return 0;
    }
    sum = first->info;
    numNodes++;
    Node* curNode = first->next;
    while(curNode != NULL){
        sum += curNode->info;
        numNodes++;
        curNode = curNode->next;
    }
    double average = sum / numNodes;
    return average;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    if(first == nullptr){
        first = newNode;
    } else{
        newNode->next = first;
        first = newNode;
    }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){ //unfinished
    if (this == &source){
        return *this;
    }
    clear(first);
    first = nullptr;
    Node *n = source.first;
    while(n){   
        append(n->info);
        n = n->next;
        }
    return *this;
}

void IntList::clear(Node* n){
    if(n == nullptr){
        return;
    }
    clear(n->next);
    delete n;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
