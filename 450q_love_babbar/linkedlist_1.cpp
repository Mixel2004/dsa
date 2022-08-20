//https://www.geeksforgeeks.org/reverse-a-linked-list/
//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
	Node (int x) {
		data = x;
		next = NULL;
	}
};
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* Inverse(struct Node * Head, struct Node ** Head2) {
        if(Head == nullptr) {
            *Head2 = new struct Node(0);
            return *Head2;
        }
    	struct Node *p;
    	p = Inverse(Head->next, Head2);
        if(Head->next!=nullptr) p = p->next;
    	p->data = Head->data;
    	p->next = new struct Node(0);
    	return p;
    }
    struct Node* reverseList(struct Node *head)
    {
        struct Node* Head2, *p;
        p = Inverse(head, &Head2);
        p->next = nullptr;
        return Head2;
    }  
};


// Iterative Method 
// while (current != NULL) {
//         // Store next
//         next = current->next;
//         // Reverse current node's pointer
//         current->next = prev;
//         // Move pointers one position ahead.
//         prev = current;
//         current = next;
//     }
//     head = prev;
// }

// Recursions Method
// Node* reverse(Node* head)
// {
//     if (head == NULL || head->next == NULL)
//         return head;

//     /* reverse the rest list and put
//       the first element at the end */
//     Node* rest = reverse(head->next);
//     head->next->next = head;

//     /* tricky step -- see the diagram */
//     head->next = NULL;

//     /* fix the head pointer */
//     return rest;
// }

void printList(struct Node *node)
{
	while (node != nullptr)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		struct Node* head = new struct Node(0);
		struct Node* tail = head;
		cin>>head->data;
		for(int i=0;i<n-1;i++) {
			int x;
			cin>>x;
			tail->next = new struct Node(0);
			tail = tail->next;
			tail->data = x;
		}
		tail->next = nullptr;
		Solution ob;
		head = ob.reverseList(head);
		printList(head);
		cout<<endl;
	}
	return 0;
}
