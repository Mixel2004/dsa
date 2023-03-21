#include <bits/stdc++.h> 
class Deque
{
    int * arr;
    int head;
    int tail;
    int n;

    public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        arr = new int[n];
        this->n = n;
        head = -1;
        tail = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(head == -1) {
            head = 0;
            tail = 0;
            arr[head] = x;
            return true;
        }
        if ((head + n - 1) % n == tail) return false;
        head = (head + n - 1) % n;
        arr[head] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(head == -1) {
            head = 0;
            tail = 0;
            arr[head] = x;
            return true;
        }
        if ((tail+1) % n == head) return false;
        tail = (tail + 1) % n;
        arr[tail] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(head == -1) return -1;
        int val = arr[head];
        if(head == tail) {
            head = -1;
            tail = -1;
        } else head = (head + 1) % n;
        return val;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(head == -1) return -1;
        int val = arr[tail];
        if(head == tail) {
            head = -1;
            tail = -1;
        } else tail = (tail + n - 1) % n;
        return val;   
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(head == -1) return -1;
        return arr[head];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(head == -1) return -1;
        return arr[tail];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        return head == -1;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        return (tail + 1) % n == head;
    }
};
