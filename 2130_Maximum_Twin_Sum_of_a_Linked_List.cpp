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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode * temp = head;
        while(temp != NULL) {
            n++;
            temp = temp->next;
        }
        vector<int> a(n/2);
        temp = head;
        int i;
        for(i = 0; i < n/2; i++) {
            a[i] = temp->val;
            temp = temp->next;
        }
        i--;
        int ans = 0;
        for(; i >= 0; i--) {
            ans = max(ans, a[i] + temp->val);
            temp = temp->next;
        }
        return ans;

    }
};
