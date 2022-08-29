// https://www.codechef.com/submit/ABITEZ?tab=statement

#include<bits/stdc++.h>

#define int long long
#define gap ' '
#define pb push_back

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i=0; i<n;i++) {
        int a;
        cin >> a;
        v.pb(a);
    }
    map<int, int> m;
    int ans = 0;
    for(int i=n-1; i>=0;i--) {
        int x = v[i];
        int y = (k-x) ^ x;
        if(m.find(y) != m.end()) {
            ans += m[y];
        }
        m[x]++;
    }
    cout << ans << endl;
}

signed main() {
    // #ifndef ONLINE_JUDGE
    // 	freopen("input.txt", "r", stdin);
    // 	freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
