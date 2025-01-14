#include <iostream>
#include <vector>
using namespace std;

int main() {
    int array_size, q_size, tmp, left, right;
    long long now_sum = 0;

    vector<int> array;
    vector<long long> sum_array;
    cin >> array_size >> q_size;

    for (int i = 0; i < array_size; i++) {
        cin >> tmp;
        array.push_back(tmp);
    }

    for (int i = 0; i < array_size; i++) {
        now_sum += array[i];
        sum_array.push_back(now_sum);
    }
   
    while (q_size--) {
        cin >> left >> right;   
        long long big = sum_array[right - 1];
        long long small = left - 2< 0 ? 0 : sum_array[left - 2];
        cout << big - small << endl;
    }
    return 0;
}