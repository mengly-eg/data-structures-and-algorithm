#include <iostream>
using namespace std;

// Element structure for the doubly linked list
struct Element {
    int data;
    Element* next;
    Element* prev;
};

// List structure to manage the doubly linked list
struct DLL {
    Element* head;
    Element* tail;
};

// Function to create an empty list
DLL* createEmptyList() {
    DLL* ls = new DLL();
    ls->head = NULL;
    ls->tail = NULL;
    return ls;
}

// Function to add a number to the beginning of the list
void addBegin(DLL* ls, int value) {
    Element* e = new Element();
    e->data = value;
    e->next = NULL;
    e->prev = NULL;

    if (ls->head == NULL) {
        // List is empty
        ls->head = e;
        ls->tail = e;
    } else {
        // Add to the beginning
        e->next = ls->head;
        ls->head->prev = e;
        ls->head = e;
    }
}

// Function to add a number to the end of the list
void addEnd(DLL* ls, int value) {
    Element* e = new Element();
    e->data = value;
    e->next = NULL;
    e->prev = NULL;

    if (ls->head == NULL) {
        // List is empty
        ls->head = e;
        ls->tail = e;
    } else {
        // Add to the end
        e->prev = ls->tail;
        ls->tail->next = e;
        ls->tail = e;
    }
}

// Function to add a number at a specific position in the list
void addAtPosition(DLL* ls, int value, int position) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    Element* e = new Element();
    e->data = value;

    // Position 1 means insert at the beginning
    if (position == 1) {
        addBegin(ls, value);
        return;
    }

    // Traverse to find the position
    Element* current = ls->head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        cout << "Position out of range!" << endl;
        delete e;
        return;
    }

    // If we're at the tail, add at the end
    if (current->next == NULL) {
        current->next = e;
        e->prev = current;
        ls->tail = e;
    } else {
        // Insert in the middle
        e->next = current->next;
        e->prev = current;
        current->next->prev = e;
        current->next = e;
    }
}

// Function to display the list forward
void displayList(DLL* ls) {
    if (ls->head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "List (Forward): ";
    Element* current = ls->head;
    while (current != NULL) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Function to display the list backward
void displayListBackward(DLL* ls) {
    if (ls->tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "List (Backward): ";
    Element* current = ls->tail;
    while (current != NULL) {
        cout << current->data << " <-> ";
        current = current->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create an empty doubly linked list
    DLL* myList = createEmptyList();

    // Add numbers to the beginning
    cout << "Adding 10, 20, 30 to the beginning:" << endl;
    addBegin(myList, 10);
    addBegin(myList, 20);
    addBegin(myList, 30);
    displayList(myList);
    displayListBackward(myList);
    cout << endl;

    // Add numbers to the end
    cout << "Adding 5, 15 to the end:" << endl;
    addEnd(myList, 5);
    addEnd(myList, 15);
    displayList(myList);
    displayListBackward(myList);
    cout << endl;

    // Add number at a specific position
    cout << "Adding 25 at position 3:" << endl;
    addAtPosition(myList, 25, 3);
    displayList(myList);
    displayListBackward(myList);
    cout << endl;

    cout << "Adding 35 at position 1:" << endl;
    addAtPosition(myList, 35, 1);
    displayList(myList);
    displayListBackward(myList);
    cout << endl;

    return 0;
}
