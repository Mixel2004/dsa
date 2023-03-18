#include<bits/stdc++.h>

using namespace std;

class SpecialStack {
    // Define the data members.
    stack<int> s;
    int minimum;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()) {
            s.push(data);
            minimum = data;
            return;
        }
        if(data < minimum) {
            int value = 2*data - minimum;
            minimum = data;
            s.push(value);
            return;
        }
        s.push(data);
    }

    int pop() {
        if(s.empty()) return -1;
        int cur = s.top();
        if(cur >= minimum) {
            s.pop();
            return cur;
        }
        int value = 2*minimum - cur;
        int temp = minimum;
        minimum = value;
        s.pop();
        return temp;
    }

    int top() {
        if (s.empty()) return -1;
        int cur = s.top();
        if(cur >= minimum) return cur;
        return minimum;
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        return minimum;
    }
};
