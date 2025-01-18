class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            int num = 0, tmp = i;
            while (tmp) {
                tmp = tmp & (tmp - 1);
                num++;
            }
            res.push_back(num);
        }
        return res;
    }
};