#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string& s) {
        if (s.size() == 0)
            return 0;
        int max_len = 1;
        std::unordered_set<char> set{s[0]};
        for (int start = 0, end = 1; end < s.size(); ++end) {
            if (set.count(s[end]) != 0) {
                if (s[end] == s[start]) {
                    ++start;
                } else {
                    while (s[start] != s[end]) {
                        set.erase(s[start]);
                        ++start;
                    }
                    ++start;
                }
            } else {
                set.emplace(s[end]);
            }
            max_len = (max_len > set.size()) ? max_len : set.size();
            if (s.size() - end - 1 + set.size() <= max_len)
                break;
        }
        return max_len;
    }
};
