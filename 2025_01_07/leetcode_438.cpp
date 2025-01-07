class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int for_count[26] = { 0 };
        bool for_exist[26] = { false };
        int now_count = 0, left = 0, right = 0;
        vector<int> res;

        for (auto& c : p) {
            for_count[c - 'a']++;
            for_exist[c - 'a'] = true;
        }
        for (int i = 0; i < p.size(); i++) {
            right++;
            if (right > s.size()) { return res; }
            if (for_exist[s[right - 1] - 'a'] == true) {
                for_count[s[right - 1] - 'a']--;
                if (for_count[s[right - 1] - 'a'] >= 0) { now_count++; }
            }
        }
        if (now_count == p.size()) { res.push_back(left); }

        while (right < s.size()) {
            right++;
            if (for_exist[s[right - 1] - 'a'] == true) {
                for_count[s[right - 1] - 'a']--;
                if (for_count[s[right - 1] - 'a'] >= 0) { now_count++; }
            }
            left++;
            if (for_exist[s[left - 1] - 'a'] == true) {
                for_count[s[left - 1] - 'a']++;
                if (for_count[s[left - 1] - 'a'] > 0) { now_count--; }
            }
            if (now_count == p.size()) { res.push_back(left); }
        }
        return res;
    }
};
