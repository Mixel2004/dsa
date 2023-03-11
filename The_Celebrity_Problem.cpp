//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i = 0; i < n; i++) s.push(i);
        
        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(M[a][b]) {
                s.push(b);
            } else {
                s.push(a);
            }
        }
        
        int ans = s.top();
        int sum = 0;
        for(auto it: M[ans]) sum+= it;
        if(sum != 0) return -1;
        for(int i = 0; i < n; i++) sum += M[i][ans];
        if(sum != n-1) return -1;
        return ans;
        
    }
};

class Solution2 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int> celib;
        int knows[n] = {0};
        for(int j = 0; j < n; j++) {
            int c= 0;
            for(int i = 0; i < n; i++) {
                if(M[i][j] == 1) {
                    c++;
                    knows[i]++;
                }
            }
            if(c==n-1) celib.push_back(j);
        }
        if(celib.size() == 1 && knows[celib[0]] == 0) return celib[0];
        else if(celib.size() == 0) return -1;
        for(auto it: celib) {
            if(knows[it] == 0) return it;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution2 ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
