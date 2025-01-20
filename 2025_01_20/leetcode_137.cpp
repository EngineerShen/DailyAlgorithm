class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int array[32] = { 0 };
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                array[j] += ((nums[i] & (1 << j)) >> j);
            }
        }                        

        int res = 0;
        for (int i = 0; i < 32; i++) { res |= ((array[i] % 3) << i); }
        return res;                   
    }
};