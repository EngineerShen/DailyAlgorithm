class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> hash_map = {{'c', 0}, {'r', 0}, {'o', 0}, {'a', 0}, {'k', 0}};
        for (auto& ch : croakOfFrogs) {
            if (ch == 'c') {
                if (hash_map['k'] > 0) { hash_map['k']--; }
                hash_map['c']++;
            }
            else if (ch == 'r') {
                if (hash_map['c'] > 0) { 
                    hash_map['c']--;
                    hash_map['r']++; 
                }
                else { return -1; }
            }
            else if (ch == 'o') {
                if (hash_map['r'] > 0) { 
                    hash_map['r']--;
                    hash_map['o']++; 
                }
                else { return -1; }
            }
            else if (ch == 'a') {
                if (hash_map['o'] > 0) { 
                    hash_map['o']--;
                    hash_map['a']++;
                }
                else { return -1; }
            }
            else if (ch == 'k') {
                if (hash_map['a'] > 0) { 
                    hash_map['a']--;
                    hash_map['k']++; 
                }
                else { return -1; }
            }
        }

        if (hash_map['c'] != 0 || hash_map['r'] != 0 || hash_map['o'] != 0 || hash_map['a'] != 0) { return -1; }
        return hash_map['k'];
    }
};