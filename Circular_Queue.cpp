#include <bits/stdc++.h> 

using namespace std;

class CircularQueue{
    int * arr;
    int head;
    int tail;
    int n;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        arr = new int[n];
        this->n = n;
        head = -1;
        tail = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if(head==tail && head == -1) {
            arr[0] = value;
            head = 0;
            tail = 0;
            return true;
        }
        if((tail+1)%n == head) return false;
        tail = (tail + 1) % n;
        arr[tail] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(head == tail && head == -1) return -1;
        int val = arr[head];
        if(head == tail) {
            head = -1;
            tail = -1;
        } else head = (head + 1) % n;
        return val;
    }
};

