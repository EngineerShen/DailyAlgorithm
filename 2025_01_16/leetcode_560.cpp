class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /* 
            version -1
            vector<int> array;
            int tmp = 0, count = 0;
            for (int i = 0; i < nums.size(); i++) {
                tmp += nums[i];
                array.push_back(tmp);
            }

            unordered_map<int, int> hash_map;
            hash_map.insert({0, 1});
            for (int i = 0; i < nums.size(); i++) {
                int need_sum = array[i] - k;
                if (hash_map.find(need_sum) != hash_map.end()) { count += hash_map[need_sum]; }

                if (hash_map.find(array[i]) == hash_map.end()) { hash_map.insert({array[i], 1}); }
                else { hash_map[array[i]]++; }
            }

            return count;
        */

        // version -2
        vector<int> array;
        int tmp = 0, count = 0, sum = 0;

        unordered_map<int, int> hash_map;
        hash_map.insert({0, 1});
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int need_sum = sum - k;
            if (hash_map.find(need_sum) != hash_map.end()) { count += hash_map[need_sum]; }

            if (hash_map.find(sum) == hash_map.end()) { hash_map.insert({sum, 1}); }
            else { hash_map[sum]++; }
        }

        return count;
    }
};