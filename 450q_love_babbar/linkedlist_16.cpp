// https://www.geeksforgeeks.org/check-if-a-linked-list-is-circular-linked-list/
// https://practice.geeksforgeeks.org/problems/circular-linked-list/1

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to get the middle of the linked list*/
bool isCircular(struct Node *head);

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){

        cin>>n>>k;
	    Node *head=NULL, *tail = NULL;
	    int x;
	    cin >> x;
	    head = new Node(x);
	    tail = head;
	    for(int i=0;i<n-1;i++)
	    {
	        cin>>x;
	        tail -> next = new Node(x);
	        tail = tail -> next;
	    }
        if (k==1 && n >= 1)
              tail->next = head;


    printf("%d\n", isCircular(head));
    }
    return 0;
}

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   Node *temp;
   if(head==NULL) return false;
   temp = head->next;
   while(temp!=NULL) {
       if(temp == head) return true;
       temp = temp->next;
   }
   return false;
}
