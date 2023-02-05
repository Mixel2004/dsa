#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if(sum < 0) sum = 0;
            sum += nums[i];
            num = max(num, sum);
        }
        return num;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution obj;
    cout << obj.maxSubArray(nums) << endl;
    return 0;
}
