#include <iostream>

class Node {
  public:
    int value;
    Node* next;

    Node(int value) : value(value) {}
    
};

class LL {
  Node head;

  public:
    LL(int val) : Node(val) {}

    void insert_ll(int val) {
      Node tmp = Node(val);
      tmp->next = head;
      head = tmp;
    }

    void print_ll() {
      Node tmp = head;
      if (tmp->next != nullptr) {
        cout << tmp.value << '\n';
      }
    }
};

int main() {

  LL ll(1);
  ll.insert_ll(2);
  ll.insert_ll(3);
  ll.print_ll();

  return 0;
}


