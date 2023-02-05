#include<bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > nums.size()/2) {
                return nums[i];
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int major = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == major) count++;
            else count--;
            if(count <= 0) {
                major = nums[i];
                count = 1;
            }
        }
        return major;
    }
};

int main() {
    vector<int> nums = {1,3,7,1,4,1,1,1,1,1,6,2,2};
    Solution1 obj1;
    Solution2 obj2;
    cout << obj1.majorityElement(nums) << endl;
    cout << obj2.majorityElement(nums) << endl;
    return 0;
}
