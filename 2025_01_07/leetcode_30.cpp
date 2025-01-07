class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> situation;
        for (auto& str : words) { 
            if (situation.find(str) == situation.end()) { situation.insert({str, 1}); }
            else { situation[str]++; }
        }
        int step = words[0].size();
        vector<int> res;
        string target_str;
        
        for (int i = 0; i < step; i++) {
            int left = i, right = i, now_count = 0;
            unordered_map<string, int> tmp_map(situation);
            
            for (int j = 0 ;j < words.size() ; j++) {
                right += step;
                if (right > s.size()) { return res; }
                target_str = s.substr(right - step, step);
                if (tmp_map.find(target_str) != tmp_map.end()) {
                    tmp_map[target_str]--;
                    if (tmp_map[target_str] >= 0) { now_count++; }
                }
            }
            if (now_count == words.size()) { res.push_back(left); }

            while (right <= s.size() - step) {
                right += step;
                target_str = s.substr(right - step, step);
                if (tmp_map.find(target_str) != tmp_map.end()) {
                    tmp_map[target_str]--;
                    if (tmp_map[target_str] >= 0) { now_count++; }
                }
                left += step;
                target_str = s.substr(left - step, step);
                if (tmp_map.find(target_str) != tmp_map.end()) {
                    tmp_map[target_str]++;
                    if (tmp_map[target_str] > 0) { now_count--; }
                }
                if (now_count == words.size()) { res.push_back(left); }
            }
        }
        return res;
    }
};