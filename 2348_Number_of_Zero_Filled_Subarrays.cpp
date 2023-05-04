#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long temp = 0;
        for(long long i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) temp++;
            else if(temp != 0) {
                ans += ((temp*(temp+1))/2);
                temp = 0;
            }
        }
        if(temp != 0) ans += ((temp*(temp+1))/2);
        return ans;
    }
};
