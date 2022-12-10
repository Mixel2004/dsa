#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int preOrder[nums.size()], postOrder[nums.size()];
        preOrder[0] = nums[0];
        postOrder[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); i++) {
            preOrder[i] = preOrder[i - 1] + nums[i];
        }
        for(int i = nums.size() - 2; i >= 0; i--) {
            postOrder[i] = postOrder[i + 1] + nums[i];
        }
        for(int i = 0; i < nums.size(); i++) {
            if(preOrder[i] == postOrder[i]) {
                return i;
            }
        }
        return -1;
    }
};
