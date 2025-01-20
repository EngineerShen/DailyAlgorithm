class Solution {
public:
    int getSum(int a, int b) {
        int res = 0, flag = 0, tmp1, tmp2, sum;
        for (int i = 0; i <= 31; i++) {
            tmp1 = (a >> i) & 1;
            tmp2 = (b >> i) & 1;
            sum = tmp1 + tmp2 + flag;
            if (sum == 0) { flag = 0; }
            else if (sum == 1) {
                flag = 0;
                res |= (1 << i);
            }
            else if (sum == 2) { flag = 1; }
            else if (sum == 3) {
                flag = 1;
                res |= (1 << i);
            }
        }
        return res;
    }
};