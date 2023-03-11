//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<int> nextSmall(int arr[], int n) {
        vector<int> v(n);
        stack<int> s;
        s.push(-1);
        for(int i = n-1; i >= 0; i--) {
            while(true) {
                int top = s.top();
                int temp = arr[i];
                if (top == -1 || arr[i] > arr[top]) {
                    v[i] = top;
                    break;
                }
                s.pop();
            }
            s.push(i);
        }
        return v;
    }

    vector<int> prevSmall(int arr[], int n) {
        vector<int> v(n);
        stack<int> s;
        s.push(-1);
        for(int i = 0; i < n; i++) {
            while(true) {
                int top = s.top();
                int temp = arr[i];
                if (top == -1 || arr[i] > arr[top]) {
                    v[i] = top;
                    break;
                }
                s.pop();
            }
            s.push(i);
        }
        return v;
    }

    int largestRectangleArea(int heights[], int n) {
        if(n == 0) return 0;
        vector<int> next = nextSmall(heights, n);
        vector<int> prev = prevSmall(heights, n);
        if(next[0] == -1) next[0] = n;
        int l = heights[0], b = next[0] - prev[0] - 1;
        int maxArea = l * b;

        for(int i = 1; i < n; i++) {
            if(next[i] == -1) next[i] = n;
            l = heights[i];
            b = next[i] - prev[i] - 1;
            maxArea = max(maxArea, l*b);
        }
        return maxArea;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area = largestRectangleArea(M[0], m);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(M[i][j] != 0) M[i][j] += M[i-1][j];
            }
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
