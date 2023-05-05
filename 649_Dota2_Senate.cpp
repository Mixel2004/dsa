#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int cr = 0, cd = 0;
        for(auto it: senate) {
            q.push(it);
            if(it == 'R') cr++;
            else cd++;
        }
        int a = 0;
        while(cr != 0 && cd != 0) {
            char i = q.front();
            q.pop();
            if (i=='R') {
                if(a<0) cr--;
                else q.push(i);
                a++;
            } else {
                if(a>0) cd--;
                else q.push(i);
                a--;
            }
        }
        return cr > cd ? "Radiant" : "Dire";
    }
};

int main() {
    Solution s;
    cout << s.predictPartyVictory("DRRDDR") << endl;
    return 0;
}
