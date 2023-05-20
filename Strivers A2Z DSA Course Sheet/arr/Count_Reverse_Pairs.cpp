//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int merge(vector<int>& arr, int l, int mid, int r) {
        int count = 0;
        int j = mid+1;
        for(int i = l; i <= mid; i++) {
            while(j <= r && arr[i] > (long long) 2 * arr[j]) j++;
            if(j <= (r+1)) count += (j - mid - 1);
        }
        vector<int> a1(mid-l+1), a2(r-mid);
        for(int i = l; i <= mid; i++){
            a1[i-l] = arr[i];
        }
        for(int i = mid+1; i <= r; i++) {
            a2[i-mid-1] = arr[i];
        }
        int i = 0, k = 0;
        j = 0;
        while(i < (mid-l+1) && j < (r-mid)) {
            if(a1[i] < a2[j]) {
                arr[k+l] = a1[i++];
            } else {
                arr[k+l] = a2[j++];
            }
            k++;
        }
        while(i < (mid-l+1)) {
            arr[k+l] = a1[i++];
            k++;
        }
        while(j < (r-mid)) {
            arr[k+l] = a2[j++];
            k++;
        }
        return count;
    }
    
    int mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r) return 0;
        int mid = l + (r-l)/2;
        int count = 0;
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid + 1, r);
        count += merge(arr, l, mid, r);
        return count;
    }
  public:
    int countRevPairs(int n, vector<int> arr) {
        return mergeSort(arr, 0, n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
