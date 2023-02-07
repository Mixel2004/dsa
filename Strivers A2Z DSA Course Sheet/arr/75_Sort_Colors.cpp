#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0, c1=0, c2=0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) c0++;
            else if(nums[i] == 1) c1++;
            else c2++;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(c0-- > 0) nums[i] = 0;
            else if(c1-- > 0) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution obj;
    obj.sortColors(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
