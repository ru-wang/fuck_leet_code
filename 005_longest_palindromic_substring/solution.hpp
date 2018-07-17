#pragma once

#include <array>
#include <vector>
#include <string>

enum { ODD = 0, EVEN = 1 };

struct palindrome {
    palindrome(int begin, int end)
        : begin(begin), end(end) { }
    int len() const { return end - begin; }
    int begin = 0;
    int end = 0;
};

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() <= 1) return s;

        std::array<std::vector<palindrome>, 2> palins_of;
        for (int i = 0; i < s.size(); ++i) {
            palins_of[ODD].emplace_back(i, i + 1);
            if (i + 2 <= s.size() && s[i] == s[i + 1])
                palins_of[EVEN].emplace_back(i, i + 2);
        }

        std::vector<palindrome> odd_palins;
        std::vector<palindrome> even_palins;

        for (int len = 3; len <= s.size(); len += 2) {
            if (palins_of[ODD][0].len() == len - 2) {
                for (auto& odd_palin : palins_of[ODD]) {
                    int prefix = odd_palin.begin - 1;
                    int suffix = odd_palin.end + 1;
                    if (prefix >= 0 && suffix <= s.size() && s[prefix] == s[suffix-1])
                        odd_palins.emplace_back(prefix, suffix);
                }
            }
            if (palins_of[EVEN].size() && palins_of[EVEN][0].len() == len - 1) {
                for (auto& even_palin : palins_of[EVEN]) {
                    int prefix = even_palin.begin - 1;
                    int suffix = even_palin.end + 1;
                    if (prefix >= 0 && suffix <= s.size() && s[prefix] == s[suffix-1])
                        even_palins.emplace_back(prefix, suffix);
                }
            }

            if (odd_palins.empty() && even_palins.empty())
                break;
            if (not odd_palins.empty())
                palins_of[ODD] = odd_palins;
            if (not even_palins.empty())
                palins_of[EVEN] = even_palins;

            odd_palins.clear();
            even_palins.clear();
        }

        if (palins_of[EVEN].size() && palins_of[EVEN][0].len() > palins_of[ODD][0].len())
            return std::string(s.begin() + palins_of[EVEN][0].begin,
                               s.begin() + palins_of[EVEN][0].end);
        else
            return std::string(s.begin() + palins_of[ODD][0].begin,
                               s.begin() + palins_of[ODD][0].end);
    }
};
