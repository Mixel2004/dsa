// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 1;
        int n = s.size();
        for(int i = 1; i < n; i++) {
            if(s[i] != ' ') {
                if(s[i-1] == ' ') {
                    ans = 1;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};
