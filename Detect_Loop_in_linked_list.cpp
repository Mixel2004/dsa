// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        set<Node*> s;
        s.insert(head);
        int c = 1;
        while(head != NULL) {
            head = head->next;
            s.insert(head);
            if(s.size() == c) return true;
            else {
                c=s.size();
            }
        }
        return false;
    }
};
