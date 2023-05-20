#include<bits/stdc++.h>

using namespace std;

class Solution {
    int merge(vector<int>& arr, int l, int mid, int r) {
        int count = 0;
        int j = mid+1;
        for(int i = l; i <= mid; i++) {
            while(j <= r && arr[i] > (long long) 2 * arr[j]) j++;
            if(j <= (r+1)) count += (j - mid - 1);
        }
        vector<int> a1(mid-l+1), a2(r-mid);
        for(int i = l; i <= mid; i++){
            a1[i-l] = arr[i];
        }
        for(int i = mid+1; i <= r; i++) {
            a2[i-mid-1] = arr[i];
        }
        int i = 0, k = 0;
        j = 0;
        while(i < (mid-l+1) && j < (r-mid)) {
            if(a1[i] < a2[j]) {
                arr[k+l] = a1[i++];
            } else {
                arr[k+l] = a2[j++];
            }
            k++;
        }
        while(i < (mid-l+1)) {
            arr[k+l] = a1[i++];
            k++;
        }
        while(j < (r-mid)) {
            arr[k+l] = a2[j++];
            k++;
        }
        return count;
    }

    int mergeSort(vector<int>& nums, int l, int r) {
        if(l >= r) return 0;
        int mid = l + (r-l)/2;
        int count = 0;
        count += mergeSort(nums, l, mid);
        count += mergeSort(nums, mid + 1, r);
        count += merge(nums, l, mid, r);
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,4,3,5,1};
    cout << s.reversePairs(nums) << endl;
    nums = {5,4,3,2,1};
    cout << s.reversePairs(nums) << endl;
    return 0;
}
