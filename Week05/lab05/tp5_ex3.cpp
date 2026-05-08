#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Product structure
struct Product {
    int productId;
    string name;
    double price;
};

// Element structure for linked list node
struct Element {
    Product product;
    Element* next;
};

// List structure for managing the linked list
struct ListProduct {
    Element* head;
};

// create an empty list
ListProduct* createEmptyList() {
    ListProduct* newList = new ListProduct();
    newList->head = NULL;
    return newList;
}

// add product to the beginning of the list (when price < 50)
void addProductToBegin(ListProduct* list, int id, string name, double price) {
    if (price >= 50) {
        cout << "Error: Price must be less than $50 to add at the beginning!" << endl;
        return;
    }

    Element* newElement = new Element();
    newElement->product.productId = id;
    newElement->product.name = name;
    newElement->product.price = price;
    newElement->next = list->head;
    list->head = newElement;

    cout << "Product added to begin: " << name << endl;
}

// add product to the end of the list (when price >= 50)
void addProductToEnd(ListProduct* list, int id, string name, double price) {
    if (price < 50) {
        cout << "Error: Price must be at least $50 to add at the end!" << endl;
        return;
    }

    Element* newElement = new Element();
    newElement->product.productId = id;
    newElement->product.name = name;
    newElement->product.price = price;
    newElement->next = NULL;

    if (list->head == NULL) {
        list->head = newElement;
    } else {
        Element* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newElement;
    }

    cout << "Product added to end: " << name << endl;
}

// display all products in the list
void display(ListProduct* list) {
    cout << "\n========== Product List ==========" << endl;
    cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price" << endl;
    cout << "=================================" << endl;

    Element* temp = list->head;
    if (temp == NULL) {
        cout << "The list is empty!" << endl;
    } else {
        while (temp != NULL) {
            cout << left << setw(5) << temp->product.productId
                 << setw(20) << temp->product.name
                 << "$" << fixed << setprecision(2) << temp->product.price << endl;
            temp = temp->next;
        }
    }
    cout << "=================================" << endl;
}

int main() {
    ListProduct* productList = createEmptyList();

    // Test the program by adding various products
    cout << "\nAdding products to the list:" << endl;

    // Products with price < 50 (add to begin)
    addProductToBegin(productList, 101, "Pencil", 2.50);
    addProductToBegin(productList, 102, "Notebook", 5.75);
    addProductToBegin(productList, 103, "Eraser", 1.25);

    // Products with price >= 50 (add to end)
    addProductToEnd(productList, 201, "Monitor", 299.99);
    addProductToEnd(productList, 202, "Keyboard", 79.50);
    addProductToEnd(productList, 203, "Mouse", 49.99);

    // Display all products
    display(productList);

    // Clean up memory
    Element* temp;
    Element* current = productList->head;
    while (current != NULL) {
        temp = current;
        current = current->next;
        delete temp;
    }
    delete productList;

    return 0;
}
