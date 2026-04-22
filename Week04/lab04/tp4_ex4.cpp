#include <iostream>
#include <string>
#include <iomanip>
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

// Function to display all students in the list
void display(ListStudent* list) {
    cout << "\n========== STUDENT LIST ==========" << endl;
    cout << setw(8) << "ID" << setw(20) << "Name" << setw(6) << "Year" 
         << setw(20) << "Program Degree" << endl;
    cout << "===================================" << endl;
    
    Student* current = list->head;
    int count = 0;
    
    while (current != NULL) {
        cout << setw(8) << current->id << setw(20) << current->name 
             << setw(6) << current->year << setw(20) << current->programDegree << endl;
        current = current->next;
        count++;
    }
    
    cout << "===================================" << endl;
    cout << "Total students: " << count << endl << endl;
}

int main() {
    cout << "Exercise 4: Display Students and Add 2 More" << endl;
    cout << "==========================================" << endl;
    
    // Create an empty list
    ListStudent* studentList = createEmptyList();
    
    // Add 5 initial students
    Student s1 = {1001, "Alice Johnson", 2, "Computer Science"};
    Student s2 = {1002, "Bob Smith", 2, "Software Engineering"};
    Student s3 = {1003, "Charlie Brown", 2, "Information Technology"};
    Student s4 = {1004, "Diana Prince", 2, "Data Science"};
    Student s5 = {1005, "Eve Wilson", 2, "Cybersecurity"};
    
    add(s1, studentList);
    add(s2, studentList);
    add(s3, studentList);
    add(s4, studentList);
    add(s5, studentList);
    
    // Display the list
    cout << "\nFirst, displaying the initial 5 students:" << endl;
    display(studentList);
    
    // Add 2 more students
    Student s6 = {1006, "Frank Miller", 2, "Artificial Intelligence"};
    Student s7 = {1007, "Grace Lee", 2, "Cloud Computing"};
    
    add(s6, studentList);
    add(s7, studentList);
    
    // Display all students including the 2 new ones
    cout << "After adding 2 more students:" << endl;
    display(studentList);
    
    return 0;
}
