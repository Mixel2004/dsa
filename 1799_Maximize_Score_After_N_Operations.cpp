#include<bits/stdc++.h>

using namespace std;

class Solution {
    map<int, int> mp;
    bool isBitSet(int& num, int bitInd)
    {
        if ((num & (1 << bitInd)) != 0) 
            return true;
        return false;
    }

    void setBit(int& num, int bitIdx) {
        num |= (1 << bitIdx);
    }
    
    int solve(vector<int>&nums, int visited, int operation)
    {
        if (mp.find(visited) != mp.end()) return mp[visited];
            
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (isBitSet(visited, i)) continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (isBitSet(visited, j)) continue;
                
                int newVisited = visited;
                setBit(newVisited, i);
                setBit(newVisited, j);

                int currScore = operation * __gcd(nums[i], nums[j]);
                int nextMaxScore = solve(nums, newVisited, operation + 1);
                int totalScore = currScore + nextMaxScore;
                ans = max(ans, totalScore);
            }
        }
        return mp[visited] = ans;
    }

    public:
    int maxScore(vector<int>& nums) 
    {
        int n = nums.size();
        int visited = 0;
        mp.clear();
        int ans = solve(nums, visited, 1);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int>nums = {1,2,3,4,5,6};
    cout << s.maxScore(nums) << endl;

    return 0;
}
