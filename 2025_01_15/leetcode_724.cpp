class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> nums_sum;
        int tmp = 0;
        for (auto& val : nums) {
            nums_sum.push_back(tmp);
            tmp += val;
        }
        for (int i = 0; i < nums.size(); i++) {
            int leftSum = nums_sum[i];
            int rightSum = tmp - nums_sum[i] - nums[i];
            if (leftSum == rightSum) { return i; }
        }
        return -1;
    }
};
