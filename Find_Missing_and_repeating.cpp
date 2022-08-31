// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *a, int n) {
        map<int, int> m;
        int *arr = new int[2];
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            m[a[i]]++;
            if(m[a[i]] == 2) {
                arr[0] = a[i];
            } 
        }
        long long total = n*(n+1LL) / 2;
        long long ans = total - sum  + arr[0];
        arr[1] = ans;
        return arr;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
