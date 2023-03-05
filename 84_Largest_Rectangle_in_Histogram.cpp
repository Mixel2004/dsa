#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextSmall(vector<int> arr, int n) {
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

    vector<int> prevSmall(vector<int> arr, int n) {
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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
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
};

int main() {
    vector<int> arr = {2,1,5,6,2,3};
    Solution s;
    cout << s.largestRectangleArea(arr);
    return 0;
    return 0;
}
