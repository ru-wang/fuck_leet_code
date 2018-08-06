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
    int longestValidParentheses(std::string s) {
        using namespace std;

        if (s.size() < 2)
            return 0;

        auto it = s.begin();
        while (it != s.end() && *it == ')') ++it;

        for (; it != s.end(); ++it) {
            char ch = *it;
        }
    }
};
