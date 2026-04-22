#include <iostream>
#include <string>
using namespace std;

// Student element structure
struct Student {
    int id;
    string name;
    int year;
    string programDegree;
    Student* next;
};

// List structure for managing student data
struct ListStudent {
    Student* head;
    Student* tail;
};

// Function to create an empty list
ListStudent* createEmptyList() {
    ListStudent* list = new ListStudent();
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to add a student to the list
void add(Student s, ListStudent* list) {
    Student* newNode = new Student();
    newNode->id = s.id;
    newNode->name = s.name;
    newNode->year = s.year;
    newNode->programDegree = s.programDegree;
    newNode->next = NULL;
    
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

int main() {
    cout << "Exercise 3: Create and Add Students to Linked List" << endl;
    cout << "==================================================" << endl << endl;
    
    // Create an empty list
    ListStudent* studentList = createEmptyList();
    
    // Create 5 student objects
    Student s1 = {1001, "Alice Johnson", 2, "Computer Science"};
    Student s2 = {1002, "Bob Smith", 2, "Software Engineering"};
    Student s3 = {1003, "Charlie Brown", 2, "Information Technology"};
    Student s4 = {1004, "Diana Prince", 2, "Data Science"};
    Student s5 = {1005, "Eve Wilson", 2, "Cybersecurity"};
    
    // Add all students to the list
    add(s1, studentList);
    add(s2, studentList);
    add(s3, studentList);
    add(s4, studentList);
    add(s5, studentList);
    
    cout << "5 students have been added to the linked list." << endl;
    cout << "Students: " << s1.name << ", " << s2.name << ", " << s3.name 
         << ", " << s4.name << ", " << s5.name << endl;
    
    return 0;
}
