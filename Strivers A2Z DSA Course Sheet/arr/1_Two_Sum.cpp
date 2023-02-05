#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int req = target - nums[i];
            if(mp.find(req) != mp.end()) {
                return {mp[req], i};
            }
            mp[nums[i]] = i; 
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
