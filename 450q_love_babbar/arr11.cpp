// https://leetcode.com/problems/find-the-duplicate-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        int n = 0;
        for(auto it: nums) {
            s.insert(it);
            n++;
            if(n != s.size()) {
                return it;
            }
        }
        return -1;
    }
};
