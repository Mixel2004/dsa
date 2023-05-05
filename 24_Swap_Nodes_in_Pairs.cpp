#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* A) {
        if(A==NULL || A->next == NULL) return A;
        ListNode * head = A;
        if(A->next->next == NULL) {
            ListNode * temp = head;
            head = head->next;
            head->next = temp;
            temp->next = NULL;
            return head;
        }
        ListNode * prev = NULL;
        ListNode * ans = A->next;
        while(head != NULL && head->next != NULL) {
            ListNode * temp = head->next;
            ListNode * tempHead = temp->next;
            head->next = tempHead;
            temp->next = head;
            if(prev != NULL) {
                prev->next = temp;
                prev = head;
            } else {
                prev = head;
            }
            head = tempHead;
        }
        return ans;
    }
};
