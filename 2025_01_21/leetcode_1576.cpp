class Solution {
public:
    string modifyString(string s) {
        string res;
        int str_size = s.size();
        for (int i = 0; i < str_size; i++) {
            if (s[i] == '?') {
                if ((i == 0 || res[i - 1] != 'x') && (i == str_size - 1 || s[i + 1] != 'x')) {
                    res += 'x';
                }
                else if ((i == 0 || res[i - 1] != 'y') && (i == str_size - 1 || s[i + 1] != 'y')) {
                    res += 'y';
                }
                else if ((i == 0 || res[i - 1] != 'z') && (i == str_size - 1 || s[i + 1] != 'z')) {
                    res += 'z';
                }
            }
            else { res += s[i]; }
        }
        return res;
    }
};