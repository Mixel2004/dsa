// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        long long total = n * (n+1LL) / 2LL;
        long long s = 0;
        for(int i = 0; i < n-1; i++) {
            s+= array[i];
        }
        int ans = total - s;
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
