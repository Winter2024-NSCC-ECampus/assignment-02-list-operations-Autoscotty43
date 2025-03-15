#include "LinkedList.h"

int main() {
    LinkedList list;

    // Insert elements
    list.insertSorted(7);
    list.insertSorted(3);
    list.insertSorted(5);
    list.insertSorted(2);
    list.insertSorted(11);
    cout << "Sorted List: ";
    list.printList();

    // Deleting elements
    list.deleteFirst();
    cout << "After deleting first node: ";
    list.printList();

    list.deleteLast();
    cout << "After deleting last node: ";
    list.printList();

    list.deleteAtIndex(1);
    cout << "After deleting index 1: ";
    list.printList();

    // Splitting the list
    LinkedList front, back;
    list.frontBackSplit(front, back);
    cout << "Front List: ";
    front.printList();
    cout << "Back List: ";
    back.printList();

    // Merging two lists
    LinkedList listA, listB;
    listA.insertAtEnd(10);
    listA.insertAtEnd(5);
    listA.insertAtEnd(20);
    listB.insertAtEnd(15);
    listB.insertAtEnd(3);
    listB.insertAtEnd(25);

    cout << "List A before sorting: ";
    listA.printList();
    cout << "List B before sorting: ";
    listB.printList();

    sortLinkedList(listA);
    sortLinkedList(listB);

    cout << "Sorted List A: ";
    listA.printList();
    cout << "Sorted List B: ";
    listB.printList();

    LinkedList mergedList = LinkedList::mergeSortedLists(listA, listB);
    cout << "Merged Sorted List: ";
    mergedList.printList();

    return 0;
}