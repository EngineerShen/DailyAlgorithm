class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int tmp = 0, res1 = 0, res2 = 0;
        for (int i = 1; i <= nums.size() + 2; i++) {
            tmp ^= i;
            if (i - 1 < nums.size()) { tmp ^= nums[i - 1]; } 
        }
        int flag = tmp & (-tmp);

        for (int i = 1;  i <= nums.size() + 2; i++) {
            if ((i & flag) == 0) { res1 ^= i; }
            else if ((i & flag) != 0){ res2 ^= i; }
            if (i - 1 < nums.size() && ((nums[i - 1] & flag) == 0)) {  res1 ^= nums[i - 1]; } 
            else if (i - 1 < nums.size() && ((nums[i - 1] & flag) != 0)) { res2 ^= nums[i - 1]; }
        }

        return vector<int>({res1, res2});
    }
};