#include <iostream>
#include <climits>
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

// Function to find the minimum number in the list
int findMinimum(DLL* list) {
    if (list->head == NULL) {
        cout << "List is empty!" << endl;
        return INT_MIN;
    }

    int minimum = list->head->data;
    Element* current = list->head->next;
    
    while (current != NULL) {
        if (current->data < minimum) {
            minimum = current->data;
        }
        current = current->next;
    }

    return minimum;
}

// Function to find the maximum number in the list
int findMaximum(DLL* list) {
    if (list->head == NULL) {
        cout << "List is empty!" << endl;
        return INT_MAX;
    }

    int maximum = list->head->data;
    Element* current = list->head->next;
    
    while (current != NULL) {
        if (current->data > maximum) {
            maximum = current->data;
        }
        current = current->next;
    }

    return maximum;
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

    cout << "=== Exercise 4: Find Minimum and Maximum ===" << endl << endl;

    // Add some numbers to the list
    cout << "Adding numbers: 15, 8, 42, 23, 16, 5, 50, 12" << endl;
    addEnd(myList, 15);
    addEnd(myList, 8);
    addEnd(myList, 42);
    addEnd(myList, 23);
    addEnd(myList, 16);
    addEnd(myList, 5);
    addEnd(myList, 50);
    addEnd(myList, 12);
    displayList(myList);
    cout << endl;

    // Display list information
    cout << "List Information:" << endl;
    cout << "  Total numbers: " << countElements(myList) << endl;
    cout << "  Minimum number: " << findMinimum(myList) << endl;
    cout << "  Maximum number: " << findMaximum(myList) << endl << endl;

    // Add more numbers and test again
    cout << "Adding more numbers: 3, 100" << endl;
    addEnd(myList, 3);
    addEnd(myList, 100);
    displayList(myList);
    cout << endl;

    cout << "Updated List Information:" << endl;
    cout << "  Total numbers: " << countElements(myList) << endl;
    cout << "  Minimum number: " << findMinimum(myList) << endl;
    cout << "  Maximum number: " << findMaximum(myList) << endl;

    return 0;
}
