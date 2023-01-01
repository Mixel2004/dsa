// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

#include<bits/stdc++.h>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        while(!s.empty()) {
            curr = s.top();
            s.pop();
            v.push_back(curr->val);
            curr = curr->right;
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
        }
        return v;
    }
};
