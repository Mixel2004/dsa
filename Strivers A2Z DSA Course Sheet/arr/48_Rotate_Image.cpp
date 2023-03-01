#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    void swap(int& a, int& b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    void reverse(vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n/2; i++) {
            swap(a[i], a[n-1-i]);
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto& it: matrix) {
            reverse(it);
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    s.rotate(matrix);
    for(auto& it: matrix) {
        for(auto& jt: it) {
            cout << jt << " ";
        }
        cout << endl;
    }
    return 0;
}
