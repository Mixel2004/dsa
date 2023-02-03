#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int latest = 0;
        for(auto it: nums) {
            if(it == 0) {
                ans = max(ans, latest);
                latest = 0;
            } else latest++;
        }
        return max(ans, latest);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(nums);
    return 0;
}
