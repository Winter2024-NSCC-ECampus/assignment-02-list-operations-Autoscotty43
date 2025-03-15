#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    explicit Node(int val);
};

// LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList();

    // Insertion
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertSorted(int val);

    // Deletion
    void deleteFirst();
    void deleteLast();
    void deleteAtIndex(int index);

    // Splitting
    void frontBackSplit(LinkedList &front, LinkedList &back) const;

    // Merging
    static LinkedList mergeSortedLists(const LinkedList &A, const LinkedList &B);

    // Utility functions
    void printList() const;
};

// Sorting function for an unsorted linked list
void sortLinkedList(LinkedList &list);

#endif