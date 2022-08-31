// https://codeforces.com/contest/1722/problem/D

#include<bits/stdc++.h>
 
#define int long long
#define gap ' '
#define pb push_back
using namespace std;
 
void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = 0;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            ans += i;
            v.pb(n-2*i-1);
        }
        else {
            ans += n - i - 1;
            v.pb(2*i-n+1);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    for(auto x:v) {
        if(x<0) {
            cout << ans << gap;
            continue;
        }
        ans += x;
        cout << ans << gap;
    }
    cout << endl;
}
 
signed main() {
    //#ifndef ONLINE_JUDGE
    //	freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
    //#endif
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
