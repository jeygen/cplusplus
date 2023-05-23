#include <iostream>
#include <queue>

using namespace std;

int main() {
    // priority_queue will auto sort max to min 
    priority_queue<int> pq;

    // Insert elements into the priority queue
    pq.push(30);
    pq.push(10);
    pq.push(20);
    pq.push(50);
    pq.push(40);

    // Display elements of priority queue
    while (!pq.empty()) {
        cout << pq.top() << " "; // peek operation
        pq.pop(); // remove element
    }

    return 0;
}

/*
This declaration will auto sort min to max
priority_queue<int, vector<int>, greater<int>> pq;
