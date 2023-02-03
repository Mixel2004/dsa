#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> mp ;
        int sum = 0;
        int ans = 0;
        int rem = 0;
        for(int i = 0 ; i <nums.size();i++)
        {
            sum = sum + nums[i];
            if(sum == k)
                ans +=1;
            rem = sum -k;
            if(mp[rem])
                ans = ans + mp[rem];
            mp[sum]++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4,1};
    int k = 7;
    cout << s.subarraySum(nums,k);

    return 0;
}
