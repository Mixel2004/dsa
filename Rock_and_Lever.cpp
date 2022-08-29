// https://codeforces.com/problemset/problem/1420/B

#include<bits/stdc++.h>
 
#define int long long
#define gap ' '
#define sum_v(v) accumulate(v.begin(),v.end(),0LL)
#define max_v(v) *max_element(v.begin(),v.end())
#define min_v(v) *min_element(v.begin(),v.end())
#define print_v(v) for(auto x:v) cout<<x<<' '
#define pb push_back
#define repeat(a, b) for(int i=0;i<b;i++) cout<<a;
#define invalid cout<<-1<<endl;
#define count_1(n) __builtin_popcount(n) // count set bits (1)
#define count_lead(n) __builtin_clz(n)
#define count_trail(n) __builtin_ctz(n)
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = log2(x);
        m[x]++;
    }
    int ans = 0;
    for (auto x : m) {
        ans += x.second * (x.second - 1) / 2;
    }
    cout << ans << endl;
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
