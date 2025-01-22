class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0, end = 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            int attack_second = timeSeries[i];
            if (i != 0) {
                if (attack_second < end) {
                    res += attack_second - timeSeries[i - 1];
                }
                else {
                    res += duration;
                }
            }
            end = attack_second + duration;
        }
        return res + duration;
    }
};