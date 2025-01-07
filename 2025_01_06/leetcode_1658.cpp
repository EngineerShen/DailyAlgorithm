class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left = 0, right = 0, total = 0, max_width = 0, sum = 0;
        for (auto& val : nums) { total += val; }

        if (total - x == 0) { return nums.size(); }

        while (right < nums.size()) {
            right++;
            sum += nums[right - 1];
            if (sum == total - x) {
                max_width = max_width > (right - left) ? max_width : (right - left);
            }
            else if (sum > total - x) {
                while (left < right) {
                    left++;
                    sum -= nums[left - 1];
                    if (sum <= total - x) {
                        if (sum == total - x) {
                            max_width = max_width > (right - left) ? max_width : (right - left);
                        }
                        break;
                    }
                }
            }
        }
        
        return max_width == 0 ? -1 : nums.size() - max_width;
    }
};