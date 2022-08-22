// https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

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
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        Node* ptr, *ans;
        if(head == NULL) return -1;
        else if(head->next == NULL) return head->data;
        ptr = head;
        ans = head;
        while(ptr != NULL)
        {
            if(ptr->next != NULL) {
                ptr = ptr->next->next;
                ans = ans->next;
            } else {
                break;
            }
        }
        return ans->data;
    }
};

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}
