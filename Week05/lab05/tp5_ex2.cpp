#include <iostream>
#include <string>
using namespace std;

//storing a person's name
struct Element {
    string name;
    Element* next;
};

//managing the linked list
struct List {
    Element* head;
};

//empty list
List* createList() {
    List* newList = new List();
    newList->head = NULL;
    return newList;
}

//add a person to the beginning of the list
void addPersonToBegin(List* list, string name) {
    Element* newElement = new Element();
    newElement->name = name;
    newElement->next = list->head;
    list->head = newElement;
}

//display all people in the list
void displayList(List* list) {
    cout << "\nList of People: " << endl;
    Element* temp = list->head;
    int count = 1;
    while (temp != NULL) {
        cout << count << ". " << temp->name << endl;
        temp = temp->next;
        count++;
    }
}

//count elements in the list
int countElements(List* list) {
    int count = 0;
    Element* temp = list->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    List* peopleList = createList();

    // Add 10 friend names to the list (demonstrating the add to begin function)
    cout << "\nAdding 10 friends' names to the list:" << endl;

    addPersonToBegin(peopleList, "Kolboth");
    cout << "Added: Kolboth" << endl;
    addPersonToBegin(peopleList, "Vathanak");
    cout << "Added: Vathanak" << endl;
    addPersonToBegin(peopleList, "Chet");
    cout << "Added: Chet" << endl;
    addPersonToBegin(peopleList, "Both");
    cout << "Added: Both" << endl;
    addPersonToBegin(peopleList, "Nana");
    cout << "Added: Nana" << endl;
    addPersonToBegin(peopleList, "Caro");
    cout << "Added: Caro" << endl;
    addPersonToBegin(peopleList, "Nika");
    cout << "Added: Nika" << endl;
    addPersonToBegin(peopleList, "Sak");
    cout << "Added: Sak" << endl;
    addPersonToBegin(peopleList, "Rithysak");
    cout << "Added: Rithysak" << endl;
    addPersonToBegin(peopleList, "Heang");
    cout << "Added: Heang" << endl;

    // Display all people in the list
    displayList(peopleList);

    // Display the count
    cout << "\nTotal number of people in the list: " << countElements(peopleList) << endl;

    // Clean up memory
    Element* temp;
    Element* current = peopleList->head;
    while (current != NULL) {
        temp = current;
        current = current->next;
        delete temp;
    }
    delete peopleList;

    return 0;
}
