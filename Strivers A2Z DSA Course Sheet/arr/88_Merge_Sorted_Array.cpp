#include<bits/stdc++.h>

using namespace std;

class Solution {
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = 0;
        while(i >= 0 && j < n)  {
            if(nums1[i] > nums2[j]) {
                swap(nums1[i], nums2[j]);
                i--;
                j++;
            }
            else break;
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        i = m;
        while(i < (m+n)) {
            nums1[i++] = nums2[i-m];
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, 3);
    for(int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
