// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        vector<char> open_brackets;
        for(int i=0; i<s.size(); i++) {
            char temp = s[i];
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                open_brackets.push_back(s[i]);
            } else {
                if(open_brackets.empty()) return false;
                char top = open_brackets.back();
                open_brackets.pop_back();
                if(top == '(' && s[i] != ')') return false;
                if(top == '[' && s[i] != ']') return false;
                if(top == '{' && s[i] != '}') return false;
            }
        }
        return open_brackets.empty();
    }
};
