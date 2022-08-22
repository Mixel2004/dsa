// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int n1 = 0, n2 = 0;
    Node* ptr = head1;
    while(ptr!=NULL) {
        n1++;
        ptr = ptr->next;
    }
    ptr = head2;
    while(ptr!=NULL) {
        n2++;
        ptr = ptr->next;
    }
    if(n1>n2) {
        int diff = n1-n2;
        while(diff--) {
            head1 = head1->next;
        }
    } else if (n2>n1) {
        int diff = n2-n1;
        while(diff--) {
            head2 = head2->next;
        }
    }
    while(head1!=NULL && head2!=NULL) {
        if(head1==head2) return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}
