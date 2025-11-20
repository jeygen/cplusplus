// dynamic/runtime objects need to be by ref or pointer
// the user adds/removes nodes at runtime so need to use Node* and 'new'
// this uses the heap
// tech better to use smart_pointers for dynamic stuff
//
// if non-pointer than on the stack when function is called and auto removed
//
#include <iostream>

// ----------------------------- Node Class -----------------------------
class Node {
public:
    int data;
    Node* next;

    Node(int value)
        : data(value), next(nullptr) {}
};

// --------------------------- LinkedList Class -------------------------
class LinkedList {
private:
    Node* head;

public:
    LinkedList()
        : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    // Insert at end
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at front
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Delete first occurrence of a value
    void remove(int value) {
        if (!head)
            return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data != value)
            current = current->next;

        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // Search for a value
    bool contains(int value) const {
        Node* temp = head;
        while (temp) {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display all values
    void print() const {
        Node* temp = head;
        std::cout << "[";
        while (temp) {
            std::cout << temp->data;
            if (temp->next)
                std::cout << " -> ";
            temp = temp->next;
        }
        std::cout << "]\n";
    }

    // Remove all nodes
    void clear() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }

    // Get size of the list
    int size() const {
        int count = 0;
        Node* temp = head;
        while (temp) {
            ++count;
            temp = temp->next;
        }
        return count;
    }
};

// ----------------------------- Test Program -----------------------------
int main() {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);

    std::cout << "Initial list: ";
    list.print();

    std::cout << "Contains 20? " << (list.contains(20) ? "Yes" : "No") << "\n";
    std::cout << "Contains 99? " << (list.contains(99) ? "Yes" : "No") << "\n";

    list.remove(10);
    std::cout << "After removing 10: ";
    list.print();

    list.append(40);
    list.append(50);
    std::cout << "After adding 40, 50: ";
    list.print();

    std::cout << "List size: " << list.size() << "\n";

    list.clear();
    std::cout << "After clearing: ";
    list.print();
}

