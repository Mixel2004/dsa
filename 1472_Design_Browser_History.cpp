#include <bits\stdc++.h>

using namespace std;

struct Node {
    string value;
    Node * back;
    Node * next;
    Node(string x) {
        value = x;
        back = NULL;
        next = NULL;
    }
};

class BrowserHistory {
    Node * head;
    Node * tail;

public:
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        tail = head;
    }
    
    void visit(string url) {
        Node * newNode = new Node(url);
        tail->next = newNode;
        newNode->back = tail;
        tail = newNode;
    }
    
    string back(int steps) {
        while(steps-- && tail->back != NULL) tail = tail->back;
        return tail->value;
        
    }
    
    string forward(int steps) {
        while(steps-- && tail->next != NULL) tail = tail->next;
        return tail->value;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
