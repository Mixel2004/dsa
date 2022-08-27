// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
//https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void segregateElements(int a[],int n)
    {
        int arr1[n], arr2[n];
        int i = 0,j=0;
        for(int k=0; k<n; k++) {
            if(a[k]<0) arr2[j++] = a[k];
            else arr1[i++]=a[k];
        }
        int k;
        for(k = 0; k < i; k++) {
            a[k] = arr1[k];
        }
        for(int b = 0; b < j; b++) {
            a[k+b] = arr2[b];
        }
    }
};

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
