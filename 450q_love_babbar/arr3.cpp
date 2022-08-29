// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    void merge(int arr[], int l, int m, int r) {
        if(l == r) return;
        int n1 = m-l+1, n2 = r-m;
        int arr1[n1], arr2[n2];
        int k = 0;
        for(int i = l; i<m+1; i++ ) {
            arr1[k++] = arr[i];
        }
        k = 0;
        for(int i = m+1; i<=r; i++) {
            arr2[k++] = arr[i];
        }
        int i = 0, j = 0;
        while(i<n1 && j<n2) {
            if(arr1[i]<arr2[j]) {
                arr[l++] = arr1[i++];
            } else {
                arr[l++] = arr2[j++];
            }
        }
        while(i<n1) {
            arr[l++] = arr1[i++];
        }
        while(j<n2) {
            arr[l++] = arr2[j++];
        }
    }
  
    void mergeSort(int arr[], int l, int r) {
        if(l>=r) return;
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
  
    int kthSmallest(int arr[], int l, int r, int k) {
        mergeSort(arr, l, r);
        return arr[k-1];
    }
};
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
