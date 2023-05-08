#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        int n = preorder.size();
        for(int i = 0 ;i < n; i++) {
            mp[inorder[i]] = i;
        }
        TreeNode * head = new TreeNode(preorder[0]);
        if(n==1) return head;
        for(int i = 1; i < n; i++) {
            TreeNode * temp = head;
            int val = preorder[i];
            TreeNode * newNode = new TreeNode(val);
            while(true) {
                if(mp[temp->val] < mp[val]) {
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


int main() {
    Solution s;
    vector<int> pre = {3,9,20,15,7};
    vector<int> ino = {9,3,15,20,7};
    TreeNode * head = s.buildTree(pre, ino);
}
