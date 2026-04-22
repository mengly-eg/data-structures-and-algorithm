#include <iostream>
#include <string>
using namespace std;

// Student element structure
struct Student {
    int id;                
    string name;            
    int year;               
    string programDegree;   
    Student* next;           // Pointer to the next student node
};

// List structure for managing student data
struct ListStudent {
    Student* head;           // Pointer to the first student
    Student* tail;           // Pointer to the last student
};

int main() {
    cout << "Exercise 2: Student Linked List Structure Definition" << endl;
    cout << "====================================================" << endl;
    cout << "\nStructures defined:" << endl;
    cout << "- Student: Contains ID, name, year, programDegree, and next pointer" << endl;
    cout << "- ListStudent: Contains head and tail pointers" << endl;
    cout << "\nThese structures can store unlimited student data." << endl;
    
    return 0;
}
