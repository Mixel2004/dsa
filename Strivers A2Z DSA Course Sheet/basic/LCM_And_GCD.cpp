//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long hcf(long long A, long long B) {
        if(B==0) return A;
        return hcf(B, A%B);
    }
    
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long> ans;
        long long h = hcf(A, B);
        ans.push_back(((A*B)/h));
        ans.push_back(h);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
