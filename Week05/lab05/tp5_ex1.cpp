#include <iostream>
#include <cctype>
using namespace std;

// Element structure
struct Element {
    char data;
    Element* next;
};

// List structure
struct List {
    Element* head;
    Element* tail;
};

//create an empty list
List* createList() {
    List* newList = new List();
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

//add an element to the end of the list
void addToEnd(List* list, char value) {
    Element* newElement = new Element();
    newElement->data = value;
    newElement->next = NULL;

    if (list->head == NULL) {
        list->head = newElement;
        list->tail = newElement;
    } else {
        list->tail->next = newElement;
        list->tail = newElement;
    }
}

//display all elements in the list
void displayList(List* list, string listName) {
    cout << "\n" << listName << ": ";
    Element* temp = list->head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create two lists
    List* smallLetters = createList();
    List* capitalLetters = createList();

    // Add small letters (a-z)
    for (char ch = 'a'; ch <= 'z'; ch++) {
        addToEnd(smallLetters, ch);
    }

    // Add capital letters (A-Z)
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        addToEnd(capitalLetters, ch);
    }

    // Display the lists
    displayList(smallLetters, "Small Letters List");
    displayList(capitalLetters, "Capital Letters List");

    // Clean up memory
    Element* temp;
    Element* current = smallLetters->head;
    while (current != NULL) {
        temp = current;
        current = current->next;
        delete temp;
    }
    delete smallLetters;

    current = capitalLetters->head;
    while (current != NULL) {
        temp = current;
        current = current->next;
        delete temp;
    }
    delete capitalLetters;

    return 0;
}
