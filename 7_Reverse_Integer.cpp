#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x==-2147483648) return 0;
        int ans = 0;
        bool is_neg = false;
        if(x < 0) {
            is_neg = true;
            x = -x;
        }
        while(x) {
            int rem = x % 10;
            x /= 10;
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && rem > 7))
                return 0;
            ans = ans * 10 + rem;
        }
        if(is_neg) return -ans;
        return ans;
    }
};
