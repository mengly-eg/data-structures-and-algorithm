#include <iostream>
#include <cstdlib>
#include <ctime>
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

// Function to compute summation of all numbers in the list
int computeSum(DLL* list) {
    int sum = 0;
    Element* current = list->head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

// Function to count the number of elements in the list
int countElements(DLL* list) {
    int count = 0;
    Element* current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to compute average of all numbers in the list
double computeAverage(DLL* list) {
    int count = countElements(list);
    if (count == 0) return 0;
    return (double)computeSum(list) / count;
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Create an empty doubly linked list
    DLL* myList = createEmptyList();

    cout << "=== Exercise 2: Random Numbers with Sum and Average ===" << endl << endl;

    // Get number n from user
    int n;
    cout << "Enter the number of random numbers to generate: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number!" << endl;
        return 1;
    }

    // Generate n random numbers and store in the list
    cout << "\nGenerating " << n << " random numbers (range 1-100)..." << endl;
    for (int i = 0; i < n; i++) {
        int randomNum = 1 + rand() % 100; // Random number between 1 and 100
        addEnd(myList, randomNum);
    }

    // Display the list
    displayList(myList);
    cout << endl;

    // Compute summation and average
    int sum = computeSum(myList);
    double average = computeAverage(myList);
    int count = countElements(myList);

    cout << "Statistics:" << endl;
    cout << "  Total numbers: " << count << endl;
    cout << "  Summation: " << sum << endl;
    cout << "  Average: " << average << endl << endl;

    return 0;
}
