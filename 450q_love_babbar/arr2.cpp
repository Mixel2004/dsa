// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
// https://practice.geeksforgeeks.org/problems/reverse-an-array/0

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0; i<n; i++) {
	        cin >> a[i];
	    }
	    for(int i = n-1; i>=0; i--) {
	        cout << a[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
