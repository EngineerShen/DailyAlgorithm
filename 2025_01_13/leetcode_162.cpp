class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {     
            int mid = (left + right) / 2;    
            if (mid - 1 < 0) { return nums[left] < nums[right] ? right : left; }
            if (mid + 1 > nums.size() - 1) { return mid; }
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) { // 1 2 3
                left = mid + 1;
            }
            else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1]) { // 3 2 1
                right = mid - 1;
            }
            else if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) { // 5 3 4
                left = mid + 1;
            }
        }
        return left;
    }
};