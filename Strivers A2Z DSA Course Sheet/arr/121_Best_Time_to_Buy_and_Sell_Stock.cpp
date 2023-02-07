#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for(auto it: prices) {
            minPrice = min(minPrice, it);
            maxProfit = max(maxProfit, it-minPrice);
        }
        return maxProfit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution obj;
    cout << obj.maxProfit(prices) << endl;
    return 0;
}
