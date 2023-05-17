#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < n) {
            int low = i+1, high = n-1;
            while(low < high) {
                if(nums[i] + nums[low] + nums[high] < 0) {
                    int temp = nums[low];
                    while(low < high && nums[low] == temp) low++;
                } else if(nums[i] + nums[low] + nums[high] > 0) {
                    int temp = nums[high];
                    while(low < high && nums[high] == temp) high--;
                } else {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    int temp1 = nums[low], temp2 = nums[high];
                    while(low < high && nums[low] == temp1) low++;
                    while(low < high && nums[high] == temp2) high--;
                }
            }
            int temp = nums[i];
            while(i < n && nums[i] == temp) i++;
        }
        return ans;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("output.txt", "w", stdout);
    #endif
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = s.threeSum(nums);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
