// https://practice.geeksforgeeks.org/problems/element-appearing-once2552/0?

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int n){
	    int ans = -1;
	    for(int i = 0; i < n-1; i+=2) {
	        if(A[i] == A[i+1]) continue;
	        ans = A[i];
	        break;
	    }
	    if(ans == -1) ans = A[n-1];
	    return ans;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends
