class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y, res = 0;
        while (tmp) {
            tmp = tmp & (tmp - 1);
            res++;
        }
        return res;
    }
};