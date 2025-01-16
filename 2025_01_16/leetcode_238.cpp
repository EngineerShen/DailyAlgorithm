class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> array_1, array_2, res;
  
        int tmp = 1;
        for (int i = 0; i < nums.size(); i++) {
            array_1.push_back(tmp);
            tmp *= nums[i];
        }
        tmp = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            array_2.push_back(tmp);
            tmp *= nums[i];        
        }

        for (int i = 0; i < nums.size(); i++) {
            res.push_back(array_1[i] * array_2[nums.size() - 1 - i]);
        }
        return res;
    }
};