#include<bits/stdc++.h>

using namespace std;

class Solution {
    int mod = 1e9+7;
    vector<int> memo;
    int solve(int i, int zero, int one) {
        if(i < 0) return 0;
        if(i == 0) return 1;
        if(memo[i] == -1) {
             int total = ((long long)solve(i-zero, zero, one) + solve(i-one, zero, one)) % mod;
             memo[i] = total;
        }
        return memo[i];
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        memo = vector<int>(high+1, -1);
        for(int i = low; i <= high; i++) {
            ans = (ans + solve(i, zero, one)) % mod;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countGoodStrings(14, 20, 5, 7) << endl;
    return 0;
}
