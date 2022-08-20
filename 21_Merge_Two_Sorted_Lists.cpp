// https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans, *rans;
        bool check = true;
		ans = new ListNode();
        rans = ans;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val > list2->val) {
                ans->val = list2->val;
				ans->next  = new ListNode();
                list2 = list2->next;
            } else {
                ans->val = list1->val;
                ans->next  = new ListNode();
				list1 = list1->next;
            }
            ans = ans->next;
        }
        if(list1 != nullptr) {
            ans->val = list1->val;
			ans->next = list1->next;
        } else if (list2 != nullptr){
			ans->val = list2->val;
			ans->next = list2->next;
		} else return nullptr;
        return rans;
    }
};
