class Solution {
public:
    string convert(string s, int numRows) {
        if (2 * numRows - 2 == 0 ) { return s; }

        int total_size = s.size(), numCols;
        int num1 = total_size / (2 * numRows - 2);
        int num2 = total_size % (2 * numRows - 2);
        if (num2 - numRows > 0) { numCols = num1 * (numRows - 1) + 1 + num2 - numRows; }
        else { numCols = num1 * (numRows - 1) + 1; }

        char array[numRows][numCols];
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) { array[i][j] = 0; }
        }

        int count = numRows, flag = 0, now_x = 0, now_y = 0;
        for (int i = 0; i < total_size; i++) {
            array[now_x][now_y] = s[i];
            count--;
            if (count == 0 && flag == 0) {
                count = numRows - 1;
                flag = 1;
                now_x--;
                now_y++;
            }
            else if (count == 0 && flag == 1) {
                count = numRows - 1;
                flag = 0;
                now_x++;
            }
            else if (flag == 0) { now_x++; }
            else if (flag == 1) {
                now_x--;
                now_y++;
            }
        }

        string res;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) { 
                if (array[i][j] != 0) { res += array[i][j]; } 
            }
        }
        return res;
    }
};