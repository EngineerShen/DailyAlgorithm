class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int compare = nums[right];

        while (left < right) {
            int mid = (left + right + 1) / 2;  
            if (nums[mid] > compare) {
                left = mid;
            }
            else if (nums[mid] < compare) {
                right = mid;
                if (right - left == 1) {
                    return min(nums[left], nums[right]);
                }
            }
            else if (nums[mid] == compare) {
                return min(nums[left], nums[right]);
            }
        }
        return nums[left];
    }
};

