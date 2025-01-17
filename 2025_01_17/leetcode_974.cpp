class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            if ((sum += nums[i]) % k == 0) { count++; }
            int rem = sum % k;
            count += hash_map[rem - k];
            count += hash_map[rem + k];
            count += hash_map[rem];
            hash_map[rem]++;
        }
        return count;
    }
};