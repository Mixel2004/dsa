#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool hasSign = false, hasE = false, hasDot = false, hasNum = false;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'e'|| s[i] == 'E') {
                if(hasE) return false;
                if(i == 0 || i == s.size() - 1) return false;
                if(s[i - 1] == '.' && i == 1) return false;
                if(s[i + 1] == '.') return false;
                hasE = true;
            } else if(s[i] == '.') {
                if(hasDot) return false;
                if(s.size() == 1) return false;
                if(hasE) return false;
                hasDot = true;
            } else if(s[i] == '+' || s[i] == '-') {
                if(hasSign && ((s[i-1] != 'e') && (s[i-1] != 'E'))) return false;
                if(s.size() == 1) return false;
                if(i != s.size() - 1 && ((s[i + 1] == 'e') || (s[i+1] == 'E'))) return false;
                if(i != 0 && ((s[i-1] != 'e') && (s[i-1] != 'E'))) return false;
                if(i != 0 && ((s[i-1] == 'e') || (s[i-1] == 'E')) && i == s.size()-1) return false;
                hasSign = true;
            } else if(s[i] >= '0' && s[i] <= '9') {
                hasNum = true;
            } else {
                return false;
            }
        }
        if(!hasNum) return false;
        return true;
    }
};
