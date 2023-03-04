#include<bits/stdc++.h>

using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> s;
    s.push('a');
    for (auto it: expression) {
        char t = s.top();
        if (it == ')' && t == '(')
          s.pop();
        else if (it == '}' && t == '{')
          s.pop();
        else if (it == ']' && t == '[')
          s.pop();
        else s.push(it);
    }
    if (s.top() == 'a')
      s.pop();
    return s.empty();
}

int main() {
    string expression;
    cin >> expression;
    if (isValidParenthesis(expression))
      cout << "Valid" << endl;
    else cout << "Invalid" << endl;
    return 0;
}
