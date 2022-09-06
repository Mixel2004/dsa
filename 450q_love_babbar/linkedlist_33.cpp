// https://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/
// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
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
    Node *compute(Node *head)
    {
        Node *temp1 = head, *temp2 = head->next, *temp3;
        while (temp2 != NULL)
        {
            temp3 = temp2->next;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
        }
        head->next=NULL;
        Node *revh = temp1;
        int mv = revh->data;
        temp2 = revh->next;
        while (temp2 != NULL)
        {
            if(temp2->data<mv) {
                temp1->next = temp2->next;
            } else {
                mv = temp2->data;
                temp1 = temp2;
            }
            temp2 = temp2->next;
        }
        temp1 = revh, temp2 = revh->next;
        while (temp2 != NULL)
        {
            temp3 = temp2->next;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
        }
        revh->next = NULL;
        return temp1;
    }
};

int main()
{
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
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
