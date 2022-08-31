// https://codeforces.com/contest/1722/problem/C

#include<bits/stdc++.h>
 
#define int long long
#define gap ' '
#define pb push_back

using namespace std;
 
void solve() {
    int n;
    vector<string> v1,v2,v3;
    map<string, int> m;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        v1.pb(s);
        m[s]++;
    }
    for(int i = 0; i < n; i++) {
        cin >> s;
        v2.pb(s);
        m[s]++;
    }
    for(int i = 0; i < n; i++) {
        cin >> s;
        v3.pb(s);
        m[s]++;
    }
    int ans = 0;
    for(auto x:v1) {
        if(m[x] == 1) ans+=3;
        else if(m[x] == 2) ans+=1;
    }
    cout << ans << gap;
    ans = 0;
    for(auto x:v2) {
        if(m[x] == 1) ans+=3;
        else if(m[x] == 2) ans+=1;
    }
    cout << ans << gap;
    ans = 0;
    for(auto x:v3) {
        if(m[x] == 1) ans+=3;
        else if(m[x] == 2) ans+=1;
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
