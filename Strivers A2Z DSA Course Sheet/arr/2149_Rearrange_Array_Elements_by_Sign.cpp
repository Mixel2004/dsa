#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i=0, j=0;
        vector<int> ans;
        while(i<nums.size() && j<nums.size()) {
            if(nums[i] >= 0) {
                while(nums[i] >= 0 && i<nums.size()) i++;
                if(i>=nums.size()) break;
            }
            if(nums[j] < 0) {
                while(nums[j] < 0 && j<nums.size()) j++;
                if(j>=nums.size()) break;
            }
            ans.push_back(nums[j++]);
            ans.push_back(nums[i++]);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}
