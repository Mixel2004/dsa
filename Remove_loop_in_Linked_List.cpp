// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        set<Node*> s;
        s.insert(head);
        int c = 1;
        while(head!=NULL) {
            s.insert(head->next);
            if(s.size() == c) {
                head->next=NULL;
            } else {
                c = s.size();
            }
            head = head->next;
        }
    }
};
