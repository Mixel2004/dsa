#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
       int ans = 0;
       int n = mat.size();
        for(int i = 0; i<n; i++) {
            ans+=mat[i][i];
            int j = n - i - 1;
            if(j!=i) {
                ans+=mat[i][j];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    cout << s.diagonalSum(mat) << endl;
    return 0;
}
