#include <bits/stdc++.h> 


bool checkRedundant(stack<char> &s) {
    bool isRedundant = true;
    char top = s.top();
    s.pop();
    while(top != '(' && !s.empty()) {
        if(top == ')') {
            if(checkRedundant(s) == true) return true;
            if (s.empty()) return false;
        } else isRedundant = false;
        top = s.top();
        s.pop();
    }
    return isRedundant;
}

bool findRedundantBrackets(string &s)
{
    stack<char> sk;
    for(auto &it: s) {
        if(it >= 'a' && it <= 'z') continue;
        sk.push(it);
    }
    if (sk.empty()) return false;
    return checkRedundant(sk);
}
