/*
Implement a first in first out (FIFO) queue using only two stacks. The 
implemented queue should support all the functions of a normal queue 
(push, peek, pop, and empty).

Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

    You must use only standard operations of a stack, which means only push 
    to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively. You 
    may simulate a stack using a list or deque (double-ended queue) as long 
    as you use only a stack's standard operations.

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

 

Constraints:

    1 <= x <= 9
    At most 100 calls will be made to push, pop, peek, and empty.
    All the calls to pop and peek are valid.

 

Follow-up: Can you implement the queue such that each operation is amortized O(1)
time complexity? In other words, performing n operations will take overall 
O(n) time even if one of those operations may take longer.
*/

MyQueue() {

}

void push(int x) {

}

int pop() {

}

int peak() {

}

bool empty() {

}


class MyQueue {
public:
  std::stack<int> s1;
  std::stack<int> s2;

  MyQueue() {

  }

  void push(int x) {
   s1.push(x); 
  }

  int pop() {
    int tmp;
    if (s2.empty() && !s1.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
        tmp = s2.top();
      }
      s2.pop();
      tmp = s2.top();
    }
    else {
      while (!s2.empty() && s1.empty()) {
        s1.push(s2.top());
        s2.pop();
        tmp = s1.top();
      }
      s1.pop();
      tmp = s1.top();
    }
    return tmp;
  }

  int peek() {
    int tmp;
    if (s2.empty() && !s1.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
        tmp = s2.top();
      }
    }
    else {
      while (!s2.empty() && s1.empty()) {
        s1.push(s2.top());
        s2.pop();
        tmp = s1.top();
      }
    }
    return tmp;
  }

  bool empty() { return (s1.empty() && s2.empty()); }
};

void push(int x) {
    s1.push(x);
}

int pop() {
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    if (!s2.empty()) { // Just to be sure before popping
        int tmp = s2.top();
        s2.pop();
        return tmp;
    }
    // Ideally, we should handle an error here since queue is empty
    return -1; // placeholder error value
}

int peek() {
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    if (!s2.empty()) { // Just to be sure before peeking
        return s2.top();
    }
    // Ideally, we should handle an error here since queue is empty
    return -1; // placeholder error value
}

bool empty() {
    return s1.empty() && s2.empty();
}

