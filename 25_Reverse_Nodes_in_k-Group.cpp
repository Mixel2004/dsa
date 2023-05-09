#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode * head) {
    while(head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        if(head == NULL || head->next == NULL) return head;
        ListNode * prev = head;
        ListNode * subHead = head->next;
        head->next = NULL;
        int temp = k-1;
        while(subHead != NULL && temp--) {
            ListNode * next = subHead->next;
            subHead->next = head;
            head = subHead;
            subHead = next;
        }
        ListNode * next;
        while(subHead != NULL) {
            temp = k-1;
            ListNode * tempNode = subHead;
            while(temp-- && tempNode != NULL) tempNode = tempNode->next;
            if(tempNode == NULL) {
                prev->next = subHead;
                return head;
            }
            else {
                temp = k-1;
                tempNode = subHead;
            }
            ListNode * curr = tempNode->next;
            tempNode->next = NULL;
            if(curr == NULL) next = NULL;
            
            while(temp-- && curr != NULL) {
                next = curr->next;
                curr->next = tempNode;
                tempNode = curr;
                curr = next;
            }
            prev->next = tempNode;
            prev = subHead;
            subHead = next;
        }
        return head;
    }
};


int main() {
    Solution s;
    ListNode * head = new ListNode(1);
    ListNode * tempNode = head;
    tempNode->next  = new ListNode(2);
    tempNode = tempNode->next;
    tempNode->next  = new ListNode(3);
    tempNode = tempNode->next;
    tempNode->next  = new ListNode(4);
    tempNode = tempNode->next;
    tempNode->next  = new ListNode(5);
    tempNode = tempNode->next;
    tempNode->next = new ListNode(6);
    tempNode = tempNode->next;
    tempNode->next = new ListNode(7);
    tempNode = tempNode->next;
    tempNode->next = new ListNode(8);
    tempNode = tempNode->next;
    tempNode->next = new ListNode(9);
    tempNode = tempNode->next;
    tempNode->next = new ListNode(10);
    print(head);
    head = s.reverseKGroup(head, 3);
    print(head);
}
