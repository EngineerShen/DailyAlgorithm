class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() > 26) { return false; }
        
        int num = 0;
        for (auto& c : astr) {
            int tmp = (1 << (c - 'a'));
            int res = (num & tmp);
            if (res != 0) { return false; }
            num |= tmp;
        }

        return true;
    }
};