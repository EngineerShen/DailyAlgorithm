class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long tmp = 0;
        for (int i = 0; i < nums.size(); i++) { tmp ^= nums[i]; }
        long long flag = (tmp & (-tmp));

        int x = 0, y = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & flag) == 0) { x ^= nums[i]; }
            else { y ^= nums[i]; }
        }
        return vector<int>({x, y});
    }
};