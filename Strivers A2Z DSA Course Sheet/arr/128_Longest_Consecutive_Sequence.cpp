#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        int count = 1;
        int ans = 1;
        int prev = *(s.begin());
        for(auto it: s) {
            if(it == prev) continue;
            if(it == prev+1) count++;
            else {
                count = 1;
            }
            prev = it;
            ans = max(ans, count);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = {9,1,4,7,3,-1,0,5,8,-1,6};
    cout << s.longestConsecutive(v) << endl;
    return 0;
}
