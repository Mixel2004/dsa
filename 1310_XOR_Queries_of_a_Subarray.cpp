//https://leetcode.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> v, ans;
        v.push_back(0);
        v.push_back(arr[0]);
        for(int i = 1; i<arr.size(); i++) {
            v.push_back(arr[i]^v.back());
        }
        for(auto it:queries) {
            ans.push_back(v[it[0]]^v[it[1]+1]);
        }
        return ans;
    }
};
