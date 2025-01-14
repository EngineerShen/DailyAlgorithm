class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int left = 0, right = records.size() - 1;

        while (left < right) {   
            int mid = (left + right) / 2; 
            if (records[mid] == mid) {
                left = mid + 1;
            }
            else if (records[mid] > mid) { 
                right = mid;
            }
        }
        // left == right
        if (left == records.size() - 1 && records[left] == left) { return left + 1;}
        return left;
    }
};