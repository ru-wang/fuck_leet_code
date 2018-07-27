#pragma once

#include <iostream>
#include <string>

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty())
            return 0;
        int index = -1;
        for (int i = 0, cached_i = 0, j = 0; i < haystack.size(); ++i) {
            if (haystack[i] == needle[j]) {
                if (j == 0)
                    cached_i = i;
                if (++j == needle.size()) {
                    index = cached_i;
                    break;
                }
            } else if (j != 0) {
                j = 0;
                i = cached_i;
            }
        }
        return index;
    }
};
