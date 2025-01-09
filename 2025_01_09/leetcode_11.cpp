class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int small = height[left] < height[right] ? left : right;
        int max_res = (right - left) * height[small];

        while (left < right) {
            if (small == left) { left++; }
            else if (small == right) { right--; }
            small = height[left] < height[right] ? left : right;
            int tmp_res = (right - left) * height[small];
            max_res = max_res > tmp_res ? max_res : tmp_res;
        }
        return max_res;
    }
};