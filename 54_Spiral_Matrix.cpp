#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m==0) return ans;
        int n = matrix[0].size();
        if(n==0) return ans;
        int top = 0, bottom = m-1, left = 0, right = n-1;
        int way = 0;
        while (top <= bottom && left <= right) {
            if(way == 0) {
                for(int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
                top++;
            } else if(way == 1) {
                for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
                right --;
            } else if(way == 2) {
                for(int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
                bottom--;
            } else {
                for(int i = bottom; i>= top; i--) ans.push_back(matrix[i][left]);
                left++;
            }
            way = (way+1) % 4;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3,10},{4,5,6,11},{7,8,9,12},{13,14,15,16}};
    vector<int> ans = s.spiralOrder(matrix);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
