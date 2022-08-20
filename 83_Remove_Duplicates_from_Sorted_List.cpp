// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *temp, *ans;
        temp = new ListNode();
        ans = temp;
        ans->val = head->val;
        head = head->next;
        while(head != nullptr) {
            if(temp->val != head->val) {
                temp->next = new ListNode();
                temp = temp->next;
                temp->val = head->val;
            }
            head = head->next;
        }
        return ans;
    }
};
