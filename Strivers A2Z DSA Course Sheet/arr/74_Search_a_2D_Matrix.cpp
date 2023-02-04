#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int b_search(vector<vector<int>>& arr, int l, int h, int key) {
        while (l <= h) {
            int mid = (l + h) / 2;
            if (arr[mid][0] == key) {
                return mid;
            } else if (arr[mid][0] < key) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return h;
    }

    int b_search(vector<int>& arr, int l, int h, int key) {
        while (l <= h) {
            int mid = (l + h) / 2;
            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = b_search(matrix, 0, n - 1, target);
        if (row == -1) {
            return false;
        }
        int col = b_search(matrix[row], 0, m - 1, target);
        if (col == -1) {
            return false;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    Solution obj;
    cout << obj.searchMatrix(arr, target);

    return 0;
}
