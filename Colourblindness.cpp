// https://codeforces.com/contest/1722/problem/B

#include<bits/stdc++.h>
 
#define int long long
#define gap ' '
#define pb push_back

using namespace std;
 
void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    for(int i=0;i<s1.size();i++) {
        if(s1[i]=='G') s1[i]='B';
    }
    for(int i=0;i<s2.size();i++) {
        if(s2[i]=='G') s2[i]='B';
    }
    if(s1==s2) cout<<"YES"<<endl;
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
