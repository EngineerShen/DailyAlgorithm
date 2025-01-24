class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            int left = 0, right = 0;
            string tmp;

            while (right < res.size()) {
                right++;
                if (res[right] != res[left]) {
                    tmp += to_string(right - left);
                    tmp += res[left];
                    left = right;
                } 
            }
            res = tmp;
        }
        return res;
    }
};