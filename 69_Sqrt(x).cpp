// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0, a = 1;
        while(a*a <= x) {
            a++;
            ans++;
        }
        return ans;
    }
};
