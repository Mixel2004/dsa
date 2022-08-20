// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    int removen(ListNode* head, int n) {
		if(head->next->next == nullptr) {
			if(n == 1) {
				head->next = nullptr;
				return 0;
			} else return n-1;
		}
		int ne = removen(head->next, n);
		if(ne == 0) return 0;
		if(ne == 1) {
			head->next = head->next->next;
			return 0;
		} else return ne-1;
	}

    ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(head == nullptr) return nullptr;
		if(head->next == nullptr) return nullptr;
		int ne = removen(head, n);
		if(ne != 0) {
			return head->next;
		}
		return head;
    }
};
