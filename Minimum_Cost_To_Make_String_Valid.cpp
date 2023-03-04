#include <bits/stdc++.h> 

using namespace std;

int findMinimumCost(string str) {
  if(str.length()%2 == 1) return -1;
  stack<char> s;
  int a = 0, b = 0;
  for (auto it : str) {
    if (it == '}') {
      if(!s.empty() && s.top() == '{') {
        s.pop();
        a--;
      } else {
        s.push(it);
        b++;
      }
    } else {
      s.push(it);
      a++;
    }
  }
  return ((a+1)/2 + (b+1)/2);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        cout << findMinimumCost(str) << endl;
    }
    return 0;
}
