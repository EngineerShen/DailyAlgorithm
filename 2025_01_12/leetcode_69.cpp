class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left <= right) {
           long mid = ((long)left + (long)right + 1) / 2; 
            if ((long long)mid * mid == x) { return mid; }
            else if ((long long)mid * mid < x) { left = mid + 1; }
            else if ((long long)mid * mid > x) { right = mid - 1; }
        }
        return right;
    }
};
