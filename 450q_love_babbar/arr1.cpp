// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
// https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}

pair<long long, long long> getMinMax(long long a[], int n) {
    long long max = a[0], min = a[0];
    for(int i = 1; i<n; i++) {
        if(a[i]>max) max = a[i];
        if(a[i]< min) min = a[i];
    }
    pair<int, int>p;
    p.first = min;
    p.second = max;
    return p;
}
