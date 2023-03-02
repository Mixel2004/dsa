//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  private:
    Node * _findMid(Node * head) {
        if(head == NULL || head->next == NULL) return head;
        Node * temp = head;
        int n = 0;
        while(temp != NULL) {
            n++;
            temp = temp->next;
        }
        temp = head;
        n = ((n+1)/2) - 1;
        while(n--) {
            temp = temp->next;
        }
        return temp;
    }
    
    Node * _merge(Node * head1, Node * head2) {
        Node * newHead;
        if(head1->data < head2->data) {
            newHead = head1;
            head1 = head1->next;
        } else {
            newHead = head2;
            head2 = head2->next;
        }
        Node * tail = newHead;
        while(head1 != NULL && head2 != NULL) {
            if(head1->data < head2->data) {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
        }
        while(head1 != NULL) {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        while(head2 != NULL) {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
        return newHead;
    }
    
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head == NULL || head->next == NULL) return head;
        Node * mid = _findMid(head);
        Node * left = head;
        Node * right = mid->next;
        mid->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        head = _merge(left, right);
        return head;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
