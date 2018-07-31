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
        for (char ch : digits)
            len *= keyboard(ch).size();
        vector<string> ret(len, string(digits.size(), ' '));
        for (int i = 0; i < digits.size(); ++i) {
            const auto& chars = keyboard(digits[i]);
            int repeat = len / chars.size();
            int cycles = ret.size() / len;
            for (int j = 0, id = 0; j < cycles; ++j)
                for (int k = 0; k < chars.size(); ++k)
                    for (int l = 0; l < repeat; ++l, ++id)
                        ret[id][i] = chars[k];
            len /= chars.size();
        }
        return ret;
    }

    static const std::string& keyboard(char ch) {
        static const std::vector<std::string> keyboard_
        { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        return keyboard_[ch - '0' - 2];
    }
};
