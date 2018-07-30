#pragma once

#include <iostream>
#include <string>
#include <vector>

static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        using namespace std;
        if (digits.empty())
            return { };
        int len = 1;
        vector<string> ret(len, string(digits.size(), ' '));
        return ret;
    }

    static const std::string& keyboard(char ch) {
        static const std::vector<std::string> keyboard_
        { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        return keyboard_[ch - '0' - 2];
    }
};
