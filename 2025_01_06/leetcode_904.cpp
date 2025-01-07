class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, now_res = 0, max_res = 0;
        unordered_map<int, int> basket;

        while (right < fruits.size()) {
            right++;
            if (basket.find(fruits[right - 1]) != basket.end()) {
                basket[fruits[right - 1]]++;
                now_res++;
            }
            else {
                if (basket.size() < 2) {
                    basket.insert({fruits[right - 1], 1});
                    now_res++;
                }
                else if (basket.size() == 2) {
                    max_res = max_res > now_res ? max_res : now_res;
                    while (left < right) {
                        left++;
                        basket[fruits[left - 1]]--;
                        now_res--;
                        if (basket[fruits[left - 1]] == 0) {
                            basket.erase(fruits[left - 1]);
                            basket.insert({fruits[right - 1], 1});
                            now_res++;
                            break;
                        }
                    }
                }
            }
        }

        return max_res > now_res ? max_res : now_res;
    }
};