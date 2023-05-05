#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int n1 = 2 * numRows - 2, n2 = 0;
        string res = "";
        for (int i = 0; i < numRows-1; i++) {
            int j = i;
            while (j < s.size()) {
                res += s[j];
                j += n1;
                if (j >= s.size()) continue;
                else if (n2 != 0) res += s[j];
                j += n2;
            }
            n1 -= 2;
            n2 += 2;
        }
        int j = numRows - 1;
        while (j < s.size()) {
            res += s[j];
            j += numRows * 2 - 2;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.convert("abcdefghijklm", 5) << endl;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}
