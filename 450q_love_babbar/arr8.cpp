// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n) {
        int ans = arr[0], maxr = 0;
        for(int i = 0; i < n; i++) {
            maxr+=arr[i];
            ans = max(maxr, ans);
            if(maxr<0) maxr=0;
        }
        return ans;
    }
};

int main()
{
    int t,n;
    
    cin>>t; //input testca  ses
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
