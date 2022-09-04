// https://www.geeksforgeeks.org/program-reverse-string-iterative-recursive/
// https://practice.geeksforgeeks.org/problems/reverse-a-string/1

#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

string reverseWord(string str){
    string s=str;
    int k = 0;
    for(int i = str.size()-1 ; i>=0; i--) {
        s[k++] = str[i];
    }
    return s;
}
