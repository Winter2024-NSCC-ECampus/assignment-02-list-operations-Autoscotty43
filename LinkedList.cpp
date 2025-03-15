#include "LinkedList.h"

// Node constructor
Node::Node(const int val) : data(val), next(nullptr) {}

// LinkedList constructor
LinkedList::LinkedList() : head(nullptr) {}

// Insert at the beginning
void LinkedList::insertAtBeginning(const int val) {
    const auto newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void LinkedList::insertAtEnd(const int val) {
    const auto newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Insert in sorted order
void LinkedList::insertSorted(const int val) {
    const auto newNode = new Node(val);
    if (!head || head->data >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data < val)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete the first node
void LinkedList::deleteFirst() {
    if (!head) return;
    const Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete the last node
void LinkedList::deleteLast() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

// Delete at a given index
void LinkedList::deleteAtIndex(const int index) {
    if (!head) return;
    if (index == 0) {
        deleteFirst();
        return;
    }
    Node* temp = head;
    for (int i = 0; temp && i < index - 1; i++)
        temp = temp->next;
    if (!temp || !temp->next) return;
    Node* next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

// Split the list into two halves
void LinkedList::frontBackSplit(LinkedList &front, LinkedList &back) const {
    if (!head) return;
    Node *slow = head;
    const Node *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    front.head = head;
    back.head = slow->next;
    slow->next = nullptr;
}

// Merge two sorted lists
LinkedList LinkedList::mergeSortedLists(const LinkedList &A, const LinkedList &B) {
    LinkedList mergedList;
    Node* dummy = new Node(0);
    Node* tail = dummy;

    Node* a = A.head;
    Node* b = B.head;

    while (a && b) {
        if (a->data < b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a) ? a : b;
    mergedList.head = dummy->next;
    delete dummy;
    return mergedList;
}

// Sorting function for an unsorted linked list
void sortLinkedList(LinkedList &list) {
    if (!list.head || !list.head->next) return;
    Node* sorted = nullptr;

    Node* current = list.head;
    while (current) {
        Node* next = current->next;
        if (!sorted || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    list.head = sorted;
}

// Print the list
void LinkedList::printList() const {
    const Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}