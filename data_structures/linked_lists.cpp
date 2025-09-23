
/*
==========================================
 LinkedList Implementation in C++

 Functions:
   - insert(int value)          : Insert node at head
   - deleteValue(int value)     : Delete first occurrence of given value
   - deleteAtPosition(int pos)  : Delete node at given 0-based position
   - display()                  : Print all nodes

 Time Complexities (Singly Linked List):
   - insert at head             : O(1)
   - delete by value            : O(n)
   - delete at position         : O(n)
   - search by value            : O(n)
   - access by index            : O(n)
   - traversal (display)        : O(n)
==========================================
*/

#include <iostream>

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a node at the beginning of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Delete the first occurrence of a node with given value
    void deleteValue(int value) {
        if (head == nullptr) return; // empty list

        // Case 1: head needs to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Case 2: search through list
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        // If found
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Delete a node at a given position (0-based)
    void deleteAtPosition(int pos) {
        if (head == nullptr || pos < 0) return; // empty list or invalid pos

        // Case 1: delete head
        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Case 2: traverse to the node before the target
        Node* current = head;
        for (int i = 0; current != nullptr && i < pos - 1; i++) {
            current = current->next;
        }

        // If position is invalid (too large)
        if (current == nullptr || current->next == nullptr) return;

        // Delete the node
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};


int main() {
    // Create a linked list
    LinkedList myList;

    // Insert elements into the list
    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    myList.insert(20);

    // Display the list
    myList.display();

    return 0;
}

// c++ <list> is doubly linked list 

#include <iostream>
#include <list>

int main() {
    std::list<int> myList;

    // Insert elements into the list
    myList.push_back(5);
    myList.push_back(10);
    myList.push_back(15);
    myList.push_back(20);

    // Display the list
    for (const auto& element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}

