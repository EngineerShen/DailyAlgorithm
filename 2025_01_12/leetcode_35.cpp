class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;  
            if (target > nums[mid]) { 
                left = mid + 1;
            }
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            else if (target == nums[mid]) {
                return mid;
            }
        }
        // left == right
        if (target <= nums[left]) { return left; }
        if (target > nums[left]) { return left + 1; }
        return 0;
    }
};