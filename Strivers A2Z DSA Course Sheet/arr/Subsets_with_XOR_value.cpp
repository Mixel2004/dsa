//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int subsetXOR(vector<int> arr, int n, int K) {
        int maxv = arr[0];
        for(int i = 1; i < n; i++) maxv = max(maxv, arr[i]);
        
        int m = (1<< (int)(log2(maxv) + 1)) - 1;
        if (K > m) return 0;
        vector<vector<int>> memos(n+1, vector<int>(m+1, 0));
        memos[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                memos[i][j] = memos[i-1][j] + memos[i - 1][j ^ arr[i-1]];
            }
        }
        return memos[n][K];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends
