class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) { return vector<int>({-1, -1}); }
        int left = 0, right = nums.size() - 1;
        vector<int> res;

        while (left < right) {
            int mid = (left + right) / 2;      // to do
            if (target > nums[mid]) { left = mid + 1; }
            else if (target < nums[mid]) { right = mid - 1; }
            else if (target == nums[mid]) { right = mid; }
        }
        if (nums[left] == target) { res.push_back(left); }
        else { res.push_back(-1); }

        left = 0;  
        right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right + 1) / 2;  // to do
            if (target > nums[mid]) { left = mid + 1; }
            else if (target < nums[mid]) { right = mid - 1; }
            else if (target == nums[mid]) { left = mid; }
        }
        if (nums[right] == target) { res.push_back(right); }
        else { res.push_back(-1); }

        return res;
    }
};
