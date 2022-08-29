// https://www.geeksforgeeks.org/longest-consecutive-subsequence/
// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
// used merge sort

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	// arr[] : the input array
	// N : size of the array arr[]

	void merge(int array[], int begin, int mid, int end)
	{
		int temp = begin;
		if(end-begin == 0) return;
		int n1 = mid - begin + 1, n2 = end - mid;
		int arr1[n1], arr2[n2];
		int k = 0;
		for (int i = begin; i < mid + 1; i++)
		{
			arr1[k++] = array[i];
		}
		k = 0;
		for (int i = mid + 1; i < end+1; i++)
		{
			arr2[k++] = array[i];
		}
		int i = 0, j = 0;
		while (i < n1 && j < n2)
		{
			if (arr1[i] < arr2[j])
			{
				array[begin++] = arr1[i++];
			}
			else
			{
				array[begin++] = arr2[j++];
			}
		}
		while (i < n1)
		{
			array[begin++] = arr1[i++];
		}
		while (j < n2)
		{
			array[begin++] = arr2[j++];
		}
	}

	void mergeSort(int array[], int begin, int end)
	{
		if (begin >= end)
			return;
		int mid = begin + (end - begin) / 2;
		mergeSort(array, begin, mid);
		mergeSort(array, mid + 1, end);
		merge(array, begin, mid, end);
	}

	// Function to return length of longest subsequence of consecutive integers.
	int findLongestConseqSubseq(int arr[], int N)
	{
		if(N==1) return 1;
		int ans = 0;
		mergeSort(arr, 0, N-1);
		int c=1;
		int val = arr[0];
		for(int i = 1; i<N; i++) {
			if(arr[i]-1 == val) {
				c++;
				val = arr[i];
			} else if(arr[i] <= val) continue;
			else {
				ans = max(ans, c);
				c = 1;
				val = arr[i];
			}
		}
		ans = max(ans, c);
		return ans;
	}
};

int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
