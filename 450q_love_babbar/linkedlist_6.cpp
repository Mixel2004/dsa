// https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}

Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 if(head == NULL) return NULL;
Node *temp, *ans;
temp = new Node(0);
ans = temp;
ans->data = head->data;
head = head->next;
while(head != NULL) {
    if(temp->data != head->data) {
        temp->next = new Node(0);
        temp = temp->next;
        temp->data = head->data;
    }
    head = head->next;
}
return ans;
}
