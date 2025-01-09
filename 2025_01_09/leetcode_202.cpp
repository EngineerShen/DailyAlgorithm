class Solution {
public:
    int change(int number) {
        int res = 0;
        while (number != 0) {
            int tmp_num = number % 10;
            res += tmp_num * tmp_num;
            number = number / 10;
        }
        return res;
    }

    bool isHappy(int n) {
        int fast = n, slow = n;
        while (1) {
            fast = change(change(fast));
            slow = change(slow);
            if (slow == fast) {
                if (slow == 1) { return true; }
                else { return false; }
            }
        }
    }
};