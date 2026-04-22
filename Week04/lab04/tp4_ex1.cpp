#include <iostream>
using namespace std;

// Node/Element structure for storing a single integer
struct Node {
    int data;        // Store the integer value
    Node* next;      // Pointer to the next node in the list
};

// List structure to manage the linked list
struct List {
    Node* head;      // Pointer to the first node
    Node* tail;      // Pointer to the last node
};

int main() {
    cout << "Exercise 1: Linked List Structure Definition" << endl;
    cout << "============================================" << endl;
    cout << "\nStructures defined:" << endl;
    cout << "- Node: Contains data (int) and next pointer" << endl;
    cout << "- List: Contains head and tail pointers" << endl;
    cout << "\nThese structures can hold unlimited integer data." << endl;
    
    return 0;
}
