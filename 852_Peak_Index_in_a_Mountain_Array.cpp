#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> arr) {
        int start = 0, end = arr.size() - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
                return mid;
            } else if(arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

int main() {
    Solution s;
    vector<int> arr = {18,29,38,59,98,100,99,98,90};
    cout << s.peakIndexInMountainArray(arr) << endl;
    return 0;
}
