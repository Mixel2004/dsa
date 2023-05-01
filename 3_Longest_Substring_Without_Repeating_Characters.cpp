#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> a;
        int setSize = 0;
        int n = s.length();
        int len1 = 0;
        int len2 = 0;
        int i = 0, j = 0;
        while(i<n) {
            char c = s[i];
            a.insert(c);
            if(a.size() == setSize) {
                while(s[j] != c) {
                    a.erase(s[j]);
                    j++;
                }
                j++;
                len2 = i - j + 1;
                setSize = a.size();
            } else {
                setSize++;
                len2++;
            }
            len1 = max(len1, len2);
            i++;
        }
        return len1;
    }
};

int main() {
    string s = "tmmzuxt";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
