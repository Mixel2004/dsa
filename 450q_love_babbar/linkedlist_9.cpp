// https://www.geeksforgeeks.org/add-1-number-represented-linked-list/
// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution
{
    public:
    int add1(Node* head) {
        if(head->next == NULL) {
            if(head->data==9) {
                head->data = 0;
                return 1;
            } else {
                head->data += 1;
                return 0;
            }
        }
        int a = add1(head->next);
        if(a==0) return 0;
        if(a==1) {
            if(head->data==9) {
                head->data = 0;
                return 1;
            } else {
                head->data += 1;
                return 0;
            }
        }
    }
    Node* addOne(Node *head) 
    {
        int a = add1(head);
        if(a==0) return head;
        Node* head2 = new Node(1);
        head2->next = head;
        return head2;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
}
