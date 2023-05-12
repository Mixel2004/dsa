#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<long long> memo;
    long long solve(vector<vector<int>>& questions, int i) {
        if(i >= questions.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int temp = i + questions[i][1]+1;
        memo[i] = max(solve(questions, i+1), solve(questions, temp)+questions[i][0]);
        return memo[i];
    } 
public:
    long long mostPoints(vector<vector<int>>& questions) {
        memo = vector<long long>(questions.size(), -1);
        return solve(questions, 0);
    }
};

int main() {
    vector<vector<int>> question = {{1,2},{8,3},{5,4},{1,5},{7,3},{4,6},{10,3},{1,2},{2,4},{4,1}};
    Solution s;
    cout << s.mostPoints(question) << endl;
    return 0;
}
