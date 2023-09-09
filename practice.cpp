#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <regex>
#include <set>
#include <climits>

using namespace std;

// practice here 

class Linky_List {
  public:
    Node* head = nullptr;

    Linky_List() {}

    Linky_List(Node* head22) : head(head22) {} 

    void insert(Node* n) {
      n = head;
      head = n->next;
    }
    
    void remove_front() {
      Node* tmp = head->next;
      head->next = nullptr;
      head = temp;    
    }
}

class Node {
  public:
    int val;
    Node* next = nullptr;

    Node(int val2, Node* next2) : next(next2) val(val2) {}
}

int main() {
  return 0;
}
