// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<stack>

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        s.push('(');
        x += ')';
        for(int i = 0; i < x.size(); i++) {
            if(x[i] == '(' || x[i] == '{' || x[i] == '[') s.push(x[i]);
            else {
                if(s.empty()) return false;
                if(x[i] == ')' && s.top() != '(') return false;
                if(x[i] == '}' && s.top() != '{') return false;
                if(x[i] == ']' && s.top() != '[') return false;
                s.pop();
            }
        }
        if(s.empty()) return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
