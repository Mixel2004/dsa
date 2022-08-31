// https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(int i = 0; i<ops.size(); i++) {
            if(ops[i] == "+") v.push_back(v[v.size()-1]+v[v.size()-2]);
            else if(ops[i] == "C") v.pop_back();
            else if(ops[i] == "D") v.push_back(v.back()*2);
            else {
                string num = ops[i];
                int n=0, is_ve=0;
                for(int i = 0; i < num.length(); i++) {
                    if(num[i] == '-') {
                        is_ve = 1;
                        continue;
                    }
                    n = n*10 + (num[i]-'0');
                }
                if(is_ve) n*=(-1);
                v.push_back(n);
            }
        }
        int sum = 0;
        for(auto it:v) {
            sum+=it;
        }
        return sum;
    }
};
