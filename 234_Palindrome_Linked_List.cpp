// https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* ptr = head;
        while(ptr!=NULL) {
            ptr = ptr->next;
            n++;
        }
        if(n<2) return true;
        vector<int> v;
        int c = 0;
        ptr = head;
        while(c<(n/2)) {
            v.push_back(ptr->val);
            ptr = ptr->next;
            c++;
        }
        if(n&1) ptr = ptr->next;
        while(ptr!=NULL) {
            if(v.back() != ptr->val) return false;
            v.pop_back();
            ptr = ptr->next;
        }
        return true;
    }
};
