//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    static bool comp(vector<int>&a, vector<int>&b){
        return a[0] < b[0];
    }

    void merge(vector<vector<int>> &range) {
        int n = range.size();
        if (n == 0) return;
        stack<vector<int>> s;
        s.push(range[0]);
        for (int i = 1; i < n; i++) {
            vector<int> top = s.top();
            if (top[1] < range[i][0]) {
                s.push(range[i]);
            } else if (top[1] < range[i][1]) {
                top[1] = range[i][1];
                s.pop();
                s.push(top);
            }
        }
        vector<vector<int>> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        range.clear();
        range = ans;
    }
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(), range.end(), comp);
        merge(range);
        n = range.size();
        vector<int>ans;
        for(int i = 0 ; i < q; i++){
            bool flag = false;
            for(int j = 0 ; j < n; j++){
                int diff = range[j][1] - range[j][0] + 1;
                if(queries[i] <= diff){
                    ans.push_back(range[j][0] + queries[i] - 1);
                    flag = true;
                    break;
                }
                else{
                    queries[i] -= diff;
                }
            }
            if(!flag){
                ans.push_back(-1);
            }
        }
        return ans;
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
