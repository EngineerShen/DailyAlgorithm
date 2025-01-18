class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> res;
        int row = mat.size();
        int col = mat[0].size();

        int array[row + 2 * k][col + 2 * k];
        for (int i = 0; i < row + 2 * k; i++) {
            for (int j = 0; j < col + 2 * k; j++) {
                if (i < k || j < k) { array[i][j] = 0; }
                else {
                    if (i - k >= row || j - k >= col) { array[i][j] = 0; }
                    else { array[i][j] = mat[i - k][j - k]; }
                    array[i][j] += array[i][j - 1];
                    array[i][j] += array[i - 1][j];
                    array[i][j] -= array[i - 1][j - 1];
                }
            }
        }

        for (int i = 0; i < row; i++) {
            vector<int> tmp;
            for (int j = 0; j < col; j++) {
                int num = array[i + 2 * k][j + 2 * k];
                if (i - 1 >= 0) { num -= array[i - 1][j + 2 * k]; }
                if (j - 1 >= 0) { num -= array[i + 2 * k][j - 1]; }
                if (i - 1 >= 0 && j - 1 >= 0) { num += array[i - 1][j - 1]; }                
                tmp.push_back(num);
            }
            res.push_back(tmp);
        }
        return res;
    }
};