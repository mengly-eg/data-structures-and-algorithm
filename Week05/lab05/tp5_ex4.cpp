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

// search and display product by name
void searchByName(ListProduct* list, string searchName) {
    cout << "\n--- Search Results by Name: '" << searchName << "' ---" << endl;
    Element* temp = list->head;
    bool found = false;

    while (temp != NULL) {
        if (temp->product.name == searchName) {
            cout << left << setw(5) << "ID: " << temp->product.productId << endl;
            cout << left << setw(5) << "Name: " << temp->product.name << endl;
            cout << left << setw(5) << "Price: $" << fixed << setprecision(2) << temp->product.price << endl;
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "No product found with name: " << searchName << endl;
    }
}

// search and display products by price
void searchByPrice(ListProduct* list, double price) {
    cout << "\n========== Search Results by Price (p = $" << fixed << setprecision(2) << price << ") ==========" << endl;

    Element* temp = list->head;
    bool foundBelow = false, foundAbove = false;

    // Section 1: Products with price lower than p
    cout << "\nSection 1: Products with price LOWER than $" << price << endl;
    cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price" << endl;
    cout << "-------------------------------------------" << endl;

    temp = list->head;
    while (temp != NULL) {
        if (temp->product.price < price) {
            cout << left << setw(5) << temp->product.productId
                 << setw(20) << temp->product.name
                 << "$" << fixed << setprecision(2) << temp->product.price << endl;
            foundBelow = true;
        }
        temp = temp->next;
    }
    if (!foundBelow) {
        cout << "No products found." << endl;
    }

    // Section 2: Products with price more than p
    cout << "\nSection 2: Products with price MORE than $" << price << endl;
    cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Price" << endl;
    cout << "-------------------------------------------" << endl;

    temp = list->head;
    while (temp != NULL) {
        if (temp->product.price > price) {
            cout << left << setw(5) << temp->product.productId
                 << setw(20) << temp->product.name
                 << "$" << fixed << setprecision(2) << temp->product.price << endl;
            foundAbove = true;
        }
        temp = temp->next;
    }
    if (!foundAbove) {
        cout << "No products found." << endl;
    }
}

// Function to update product information by product ID
void updateByProductId(ListProduct* list, int id, string newName, double newPrice) {
    Element* temp = list->head;
    bool found = false;

    while (temp != NULL) {
        if (temp->product.productId == id) {
            cout << "\nUpdating Product ID " << id << ":" << endl;
            cout << "Old Name: " << temp->product.name << " -> New Name: " << newName << endl;
            cout << "Old Price: $" << fixed << setprecision(2) << temp->product.price
                 << " -> New Price: $" << newPrice << endl;

            temp->product.name = newName;
            temp->product.price = newPrice;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Product with ID " << id << " not found!" << endl;
    }
}

int main() {
    ListProduct* productList = createEmptyList();

    // Add various products to the list
    cout << "\nAdding products to the list:" << endl;

    // Products with price < 50 (add to begin)
    addProductToBegin(productList, 101, "Pencil", 2.50);
    addProductToBegin(productList, 102, "Notebook", 5.75);
    addProductToBegin(productList, 103, "Eraser", 1.25);
    addProductToBegin(productList, 104, "Pen", 3.99);

    // Products with price >= 50 (add to end)
    addProductToEnd(productList, 201, "Monitor", 299.99);
    addProductToEnd(productList, 202, "Keyboard", 79.50);
    addProductToEnd(productList, 203, "Mouse", 49.99);
    addProductToEnd(productList, 204, "Headphones", 89.99);

    // Display all products
    display(productList);

    // Test search by name
    searchByName(productList, "Monitor");
    searchByName(productList, "Keyboard");

    // Test search by price
    searchByPrice(productList, 50.0);

    // Test update function
    updateByProductId(productList, 201, "Dell Monitor", 349.99);
    updateByProductId(productList, 102, "Premium Notebook", 12.99);
    updateByProductId(productList, 999, "Non-existent", 100.0);

    // Display updated list
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
