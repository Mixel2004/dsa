/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* head = new TreeNode(postorder[n-1]);
        for(int i = n-2; i >= 0; i--) {
            TreeNode * temp = head;
            int x = postorder[i];
            TreeNode * newNode = new TreeNode(x);
            while(true) {
                if(mp[temp->val] < mp[x]) {
                   if(temp->right == NULL) {
                       temp->right = newNode;
                       break;
                   } else temp = temp->right;
                } else {
                    if(temp->left == NULL) {
                       temp->left = newNode;
                       break;
                   } else temp = temp->left;
                }
            }
        }
        return head;
    }
};
