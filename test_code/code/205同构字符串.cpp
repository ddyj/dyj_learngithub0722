#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>

class PairHash {
public:
    std::size_t operator()(const std::pair<char, char>& p) const {
        std::size_t hashValue = std::hash<char>()(p.first);
        hashValue ^= std::hash<char>()(p.second) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
        return hashValue;
    }
};

class Solution {
public:
    std::unordered_map<std::pair<char, char>, int, PairHash> s_table;

    bool isIsomorphic(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (s_table.find(std::make_pair(s[i], t[i])) == s_table.end()) {
                s_table[std::make_pair(s[i], t[i])] = s[i] - t[i];
            } else {
                if (s_table[std::make_pair(s[i], t[i])] != s[i] - t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    std::string s = "egg";
    std::string t = "add";

    bool result = solution.isIsomorphic(s, t);
    std::cout << "Is Isomorphic: " << (result ? "true" : "false") << std::endl;

    return 0;
}