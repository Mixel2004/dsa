#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
vector<int> ans;
vector<int> indexs;

int height(struct Node* node){
    if(node == NULL) return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    int height = max(leftHeight, rightHeight) + 1;
    return height;
}

void fillAns(struct Node* node, int h) {
    if(node == NULL) return;
    if(indexs[h-1] == -1) {
        indexs[h-1] = 1;
        ans[h-1] = node->data;
    }
    fillAns(node->left, h-1);
    fillAns(node->right, h-1);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    int h = height(root);
    ans.clear();
    indexs.clear();
    for(int i = 0; i < h; i++) {
        ans.push_back(-1);
        indexs.push_back(-1);
    }
    fillAns(root, h);
    reverse(ans.begin(), ans.end());
    return ans;
}
