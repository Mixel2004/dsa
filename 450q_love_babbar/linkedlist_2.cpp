// https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1


#include<bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	node *next;
	node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct node *node) 
{
	while (node != NULL) 
	{ 
		cout<<node->data<<" "; 
		node = node->next;
	} 
	cout << endl;
}

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    {
        struct node *bits_p, *bits_n, *prev, *next, *current;
        current = head;
		bits_p = NULL;
        prev = NULL, next = NULL;
		head = NULL;
        int i = 0;
        while(current != NULL) {
			bits_n = current;
            while(i++ < k && current != NULL) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
			if(head == NULL) head = prev;
			if(bits_p != NULL) bits_p->next = prev;
			bits_p = bits_n;
            i = 0;
			prev = NULL;
        }
        return head;
    }
};


int main() {
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
	node* head = NULL;
	node* temp = NULL;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(head == NULL) {
			head = new node(x);
			temp = head;
		} else {
			temp->next = new node(x);
			temp = temp->next;
		}
	}
	int k;
	cin >> k;
	Solution ob;
	head = ob.reverse(head, k);
	printList(head);
	return 0;
}
