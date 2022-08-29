// https://www.codechef.com/problems/AND

#include<bits/stdc++.h>

#define int long long
#define gap ' '
#define pb push_back

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    for(int i=0; i<n;i++) {
        int a, c=1;
        cin >> a;
        while(a) {
            if(a&1) {
                m[c]++;
            }
            a>>=1;
            c*=2;
        }
    }
    int x=0;
    for(auto i: m) {
        if(i.second > 0) {
            int a = (i.second)*(i.second-1)/2;
            x+=(a)*(i.first);
        }
    }
    cout << x << endl;
}

signed main() {
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
