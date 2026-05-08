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
    DLL* list = new DLL();
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to add a number to the beginning of the list
void addBegin(DLL* list, int value) {
    Element* e = new Element();
    e->data = value;
    e->next = NULL;
    e->prev = NULL;

    if (list->head == NULL) {
        list->head = e;
        list->tail = e;
    } else {
        e->next = list->head;
        list->head->prev = e;
        list->head = e;
    }
}

// Function to add a number to the end of the list
void addEnd(DLL* list, int value) {
    Element* e = new Element();
    e->data = value;
    e->next = NULL;
    e->prev = NULL;

    if (list->head == NULL) {
        list->head = e;
        list->tail = e;
    } else {
        e->prev = list->tail;
        list->tail->next = e;
        list->tail = e;
    }
}

// Function to add a number at a specific position in the list
void addAtPosition(DLL* list, int value, int position) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    Element* e = new Element();
    e->data = value;

    if (position == 1) {
        addBegin(list, value);
        return;
    }

    Element* current = list->head;
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

    if (current->next == NULL) {
        current->next = e;
        e->prev = current;
        list->tail = e;
    } else {
        e->next = current->next;
        e->prev = current;
        current->next->prev = e;
        current->next = e;
    }
}

// Function to display the list
void displayList(DLL* list) {
    if (list->head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "List: ";
    Element* current = list->head;
    while (current != NULL) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Function to delete one element from the beginning
void deleteBegin(DLL* list) {
    if (list->head == NULL) {
        cout << "List is empty! Cannot delete." << endl;
        return;
    }

    Element* temp = list->head;
    
    if (list->head == list->tail) {
        // Only one element in the list
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    
    delete temp;
    cout << "Element deleted from beginning." << endl;
}

// Function to delete one element from the end of the list
void deleteEnd(DLL* list) {
    if (list->tail == NULL) {
        cout << "List is empty! Cannot delete." << endl;
        return;
    }

    Element* temp = list->tail;
    
    if (list->head == list->tail) {
        // Only one element in the list
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    
    delete temp;
    cout << "Element deleted from end." << endl;
}

// Function to delete one element at a specific position
void deleteAtPosition(DLL* list, int position) {
    if (list->head == NULL) {
        cout << "List is empty! Cannot delete." << endl;
        return;
    }

    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (position == 1) {
        deleteBegin(list);
        return;
    }

    Element* current = list->head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    // Check if it's the last element
    if (current == list->tail) {
        deleteEnd(list);
        return;
    }

    // Delete from middle
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    cout << "Element deleted at position " << position << "." << endl;
}

// Function to count elements in the list
int countElements(DLL* list) {
    int count = 0;
    Element* current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    // Create an empty doubly linked list
    DLL* myList = createEmptyList();

    cout << "=== Exercise 3: Delete Operations on Doubly Linked List ===" << endl << endl;

    // Add some numbers to the list
    cout << "Adding numbers: 10, 20, 30, 40, 50" << endl;
    addEnd(myList, 10);
    addEnd(myList, 20);
    addEnd(myList, 30);
    addEnd(myList, 40);
    addEnd(myList, 50);
    displayList(myList);
    cout << endl;

    // Delete from beginning
    cout << "Deleting from beginning:" << endl;
    deleteBegin(myList);
    displayList(myList);
    cout << endl;

    // Delete from end
    cout << "Deleting from end:" << endl;
    deleteEnd(myList);
    displayList(myList);
    cout << endl;

    // Delete at position 2
    cout << "Deleting at position 2:" << endl;
    deleteAtPosition(myList, 2);
    displayList(myList);
    cout << endl;

    // Try to delete at invalid position
    cout << "Trying to delete at position 10 (invalid):" << endl;
    deleteAtPosition(myList, 10);
    displayList(myList);
    cout << endl;

    // Delete remaining elements
    cout << "Deleting remaining elements:" << endl;
    while (countElements(myList) > 0) {
        deleteBegin(myList);
    }
    displayList(myList);

    return 0;
}
