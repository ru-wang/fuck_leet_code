#pragma once

#include <iostream>
#include <string>

/*
 *  Symbol       Value
 *  I             1
 *  V             5
 *  X             10
 *  L             50
 *  C             100
 *  D             500
 *  M             1000
 */

static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int romanToInt(std::string s) {
        int int_num = 0;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (it+1 != s.end() && less(it, it+1)) {
                int_num += roman(it+1) - roman(it);
                ++it;
            } else {
                int_num += roman(it);
            }
        }
        return int_num;
    }

    bool less(
            std::string::const_iterator a,
            std::string::const_iterator b) const {
        return (roman(a) < roman(b));
    }

    int roman(std::string::const_iterator it) const {
        switch (*it) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};
