#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        int top = 0, bottom = n-1, left = 0, right = n-1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int way = 0;
        while(top <= bottom && left <= right) {
            if(way == 0) {
                for(int i = left; i <= right; i++) ans[top][i] = num++;
                top++;
            } else if(way == 1) {
                for(int i = top; i <= bottom; i++) ans[i][right] = num++;
                right--;
            } else if(way == 2) {
                for(int i = right; i >= left; i--) ans[bottom][i] = num++;
                bottom--;
            } else {
                for(int i = bottom; i >= top; i--) ans[i][left] = num++;
                left++;
            }
            way = (way+1) % 4;
        }
        return ans;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        freopen("output.txt", "w", stdout);
    #endif

    Solution s;
    vector<vector<int>> ans = s.generateMatrix(7);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
