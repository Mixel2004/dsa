// https://codeforces.com/contest/1722/problem/A

#include<bits/stdc++.h>
 
#define int long long
#define gap ' '
#define pb push_back

using namespace std;
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s=="Timru") cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
