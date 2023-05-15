//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        int temp = 2;
        long long ans = 0, n = N+1;
        while(N) {
            N /= 2;
            ans+= ((n/temp)*(temp/2));
            if(n%temp > temp/2) ans += ((n%temp) - temp/2);
            temp *= 2;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
