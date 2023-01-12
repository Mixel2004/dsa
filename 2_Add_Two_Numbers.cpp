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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        int sum = 0;
        ListNode* ans = nullptr;
        ListNode* rtr = nullptr;
        while(l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + c;
            c = sum / 10;
            ListNode* newNode = new ListNode((sum%10));
            if(ans == nullptr) {
                ans = newNode;
                rtr = ans;
            }
            else {
                ans->next = newNode;
                ans = ans->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1 != nullptr) {
            sum = c + l1->val;
            c = sum / 10;
            ListNode* newNode = new ListNode(sum%10);
            ans->next = newNode;
            ans = ans->next;
            l1=l1->next;
        }
        while(l2 != nullptr) {
            sum = c + l2->val;
            c = sum / 10;
            ListNode* newNode = new ListNode(sum%10);
            ans->next = newNode;
            ans = ans->next;
            l2=l2->next;
        }
        if(c!=0) {
            ListNode* newNode = new ListNode(c);
            ans->next = newNode;
        }
        return rtr;
    }
};
