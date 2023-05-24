#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        bool hasZero = false;
        int left = nums[0];
        int temp = 1;
        for(auto it: nums) {
            if(it == 0) {
                hasZero = true;
                temp = 1;
                continue;
            }
            temp *= it;
            left = max(temp, left);
        }
        int right = nums[0];
        temp = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i] == 0) {
                temp = 1;
                continue;
            }
            temp *= nums[i];
            right = max(temp, right);
        }
        if(hasZero) return max(max(left, right), 0);
        return max(left, right);
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,-2,4};
    cout << s.maxProduct(nums) << endl;
    nums = {-2,0,-1};
    cout << s.maxProduct(nums) << endl;
    nums = {-2};
    cout << s.maxProduct(nums) << endl;
    nums = {0,2};
    cout << s.maxProduct(nums) << endl;
    nums = {-2,3,-4};
    cout << s.maxProduct(nums) << endl;
    return 0;
}
