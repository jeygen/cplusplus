// chat gpt style

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
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
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

