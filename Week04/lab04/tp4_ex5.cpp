#include <iostream>
using namespace std;

// Node structure for storing integer data
struct Node {
    int data;
    Node* next;
};

// List structure for managing the linked list
struct List {
    Node* head;
    Node* tail;
};

// Function to create an empty list
List* createEmptyList() {
    List* list = new List();
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to add a number to the list
void addNumber(int num, List* list) {
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Function to display all numbers in the list
void displayNumbers(List* list) {
    cout << "\nAll data in the list are: ";
    Node* current = list->head;
    
    while (current != NULL) {
        cout << current->data;
        if (current->next != NULL) {
            cout << " ";
        }
        current = current->next;
    }
    cout << "." << endl;
}

// Function to compute the sum of all numbers
int computeSum(List* list) {
    int sum = 0;
    Node* current = list->head;
    
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    
    return sum;
}

int main() {
    cout << "*** A program to store number as many as possible: ***" << endl;
    
    List* numberList = createEmptyList();
    int num;
    int zeroCount = 0;
    
    while (true) {
        cout << "Enter a number: ";
        cin >> num;
        
        if (num == 0) {
            zeroCount++;
            
            if (zeroCount == 1) {
                cout << "You have entered the number 0 once. Only 1 more left. We will quit the program." << endl;
            } else if (zeroCount == 2) {
                cout << "You have entered the number 0 twice so far. The program is going to stop now." << endl;
                break;
            }
        } else {
            addNumber(num, numberList);
        }
    }
    
    // Display all numbers
    displayNumbers(numberList);
    
    // Calculate and display the sum
    int total = computeSum(numberList);
    cout << "Summation of all numbers is: " << total << endl;
    
    return 0;
}
