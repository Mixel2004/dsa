#include<bits/stdc++.h>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> v(n);
    if(n==0) return v;
    stack<int> s;
    s.push(-1);
    for(int i = n-1; i >= 0; i--) {
        while(true) {
            int top = s.top();
            if (arr[i] > top) {
                v[i] = top;
                break;
            }
            s.pop();
        }
        s.push(arr[i]);
    }
    return v;

}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        vector<int> res = nextSmallerElement(arr, n);
        for (int i = 0; i < n; i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
