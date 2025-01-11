class Solution {
public:
    int search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, mid = (left + right) / 2;
        while (left <= right) {
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else if (nums[mid] > target) {
                right = mid - 1;
            } 
            mid = (left + right) / 2;
        }
        return -1;
    }
};