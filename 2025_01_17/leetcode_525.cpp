class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_res = 0, now_sum = 0;
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) { now_sum += -1; }
            else { now_sum += 1; }

            if (now_sum == 0) { max_res = i + 1; }
            else if (hash_map.find(now_sum) != hash_map.end()) {
                max_res = max(max_res, i - hash_map[now_sum]);
            }

            if (hash_map.find(now_sum) == hash_map.end()) {
                hash_map.insert({now_sum, i});
            }
        }
        return max_res;
    }
};