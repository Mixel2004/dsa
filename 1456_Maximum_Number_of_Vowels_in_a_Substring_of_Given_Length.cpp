#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        if (k==0) return 0;
        if (s=="") return 0;
        int i = 0;
        int j = 0;
        int n = s.length();
        int curr = 0;
        while(i < k) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                curr++;
            }
            i++;
        }
        int ans = curr;
        while(i<n) {
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                curr--;
            }
            j++;
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                curr++;
            }
            i++;
            ans = max(ans, curr);
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.maxVowels("abciiidef", 3) << endl;
    return 0;
}
