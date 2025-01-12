class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int mid = (left + right + 1) / 2;   
            if (arr[mid - 1] < arr[mid]) { 
                left = mid;
            }
            else if (arr[mid - 1] > arr[mid]) {
                right = mid - 1;
            }
        }
        return left;
    }
};
