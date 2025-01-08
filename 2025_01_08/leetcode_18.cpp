class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left, right, ptr1 = nums.size() - 1, ptr2 = ptr1 - 1;
        vector<vector<int>> res;

        while (ptr1 >= 3) {
            while (ptr2 >= 2) {            // ptr1不动
                left = 0;
                right = ptr2 - 1;
                while (left < right) {     // ptr2, ptr1不动
                    if ((long)nums[left] + (long)nums[right] + (long)nums[ptr2] + (long)nums[ptr1] == target) {
                        res.push_back(vector<int>{nums[left], nums[right], nums[ptr2], nums[ptr1]});
                        while (left < right && nums[left + 1] == nums[left]) { left++; }
                        while (left < right && nums[right - 1] == nums[right]) { right--; }
                        left++;
                        right--;
                    }
                    else if ((long)nums[left] + (long)nums[right] + (long)nums[ptr2] + (long)nums[ptr1] < target) {
                        left++;
                    }
                    else if ((long)nums[left] + (long)nums[right] + (long)nums[ptr2] + (long)nums[ptr1] > target) {
                        right--;
                    }
                }
                while (ptr2 >= 2 && nums[ptr2 - 1] == nums[ptr2]) { ptr2--; }
                ptr2--;
            }
            while (ptr1 >= 3 && nums[ptr1 - 1] == nums[ptr1]) { ptr1--; }
            ptr1--;
            ptr2 = ptr1 - 1;
        }
        return res;
    }
};