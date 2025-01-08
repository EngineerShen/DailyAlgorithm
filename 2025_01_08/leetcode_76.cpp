class Solution {
public:
    string minWindow(string s, string t) {
        int for_count[128] = { 0 };
        bool for_exist[128] = { false };
        for (auto& c : t) {
            for_exist[c] = true;
            for_count[c]++;
        }
        int left = 0, right = 0, now_count = 0, width = 0, min_left = 0, min_size = s.size() + 1;

        while (right < s.size()) {
            right++;
            if (for_exist[s[right - 1]] == true) {
                for_count[s[right - 1]]--;
                if (for_count[s[right - 1]] >= 0) {
                    now_count++;
                    if (now_count == t.size()) {
                        width = right - left;
                        if (width < min_size) { 
                            min_size = width; 
                            min_left = left;
                        }
                        while (left < right) {
                            left++;
                            if (for_exist[s[left - 1]] == true) {
                                for_count[s[left - 1]]++;
                                if (for_count[s[left - 1]] > 0) {
                                    now_count--;
                                    break;
                                }
                            }
                            width = right - left;
                            if (width < min_size) { 
                                min_size = width; 
                                min_left = left;
                            }
                        }
                    }
                }
            }
        }
        return min_size == s.size() + 1 ? "" : s.substr(min_left, min_size);
    }
};
