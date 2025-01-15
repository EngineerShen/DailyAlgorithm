#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int n, m, q, tmp, x1, y1, x2, y2;
    cin >> n >> m >> q;
    
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { cin >> arr[i][j]; }
    }

    long long arr_sum [n][m];
    memset(arr_sum, 0, sizeof(arr_sum));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr_sum[i][j] = arr[i][j];
            if (i - 1 >= 0) { arr_sum[i][j] += arr_sum[i - 1][j]; }
            if (j - 1 >= 0) { arr_sum[i][j] += arr_sum[i][j - 1]; }
            if (i - 1 >= 0 && j - 1 >= 0) {
                arr_sum[i][j] -= arr_sum[i - 1][j - 1];
            }
        }
    }

    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        long long result = arr_sum[x2 - 1][y2 - 1];
        if (x1 - 2 >= 0) { result -= arr_sum[x1 - 2][y2 - 1]; }
        if (y1 - 2 >= 0) { result -= arr_sum[x2 - 1][y1 - 2]; }
        if (x1 - 2 >= 0 && y1 -  2>= 0) {
            result += arr_sum[x1 - 2][y1 - 2];
        }
        cout << result << endl;
    }
    return 0;
}
