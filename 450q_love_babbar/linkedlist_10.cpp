// https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists-set-3/
// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

class Solution
{
    public:
    int sumn(Node* h1, Node* h2) {
        if(h1->next == NULL) {
            int a = h1->data + h2->data;
            h1->data = a%10;
            return a/10;
        }
        int s = sumn(h1->next, h2->next);
        int a = h1->data + h2->data+s;
        h1->data = a%10;
        return a/10;
    }
    
    int addn(Node* l, Node* small, int diff) {
        if(diff==0) return sumn(l, small);
        int s = addn(l->next, small, diff-1);
        if(s==0) return 0;
        int a = l->data + s;
        l->data = a%10;
        return a/10;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *head, *ptr;
        int c1 = 0, c2 = 0;
        ptr = first;
        while(ptr) {
            c1++;
            ptr = ptr->next;
        }
        ptr = second;
        while(ptr) {
            c2++;
            ptr = ptr->next;
        }
        if(c1>c2) {
            int diff = c1-c2;
            int s = addn(first, second, diff);
            if(s==0) return first;
            head=new Node(s);
            head->next = first;
            return head;
        } else if(c2>c1) {
            int diff = c2-c1;
            int s = addn(second, first, diff);
            if(s==0) return second;
            head=new Node(s);
            head->next = second;
            return head;
        } else {
            int s = addn(first, second, 0);
            if(s==0) return first;
            head=new Node(s);
            head->next = first;
            return head;
        }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
