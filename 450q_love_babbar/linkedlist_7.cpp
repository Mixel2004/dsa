// https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

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

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        if(head == NULL) return NULL;
    	set<int> s;
		Node* temp = head;
		s.insert(head->data);
		while (head->next != NULL)
		{
			if(s.find(head->next->data) != s.end()) {
				head->next = head->next->next;
			} else {
				s.insert(head->next->data);
				head = head->next;
			}
		}
		return temp;
    }
};


int main() {
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
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
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
