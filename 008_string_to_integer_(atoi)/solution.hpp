#pragma once

#include <string>

class Solution {
public:
    int myAtoi(std::string str) {
        auto it = str.begin();
        while (*it == ' ') ++it;

        int sign = 1;
        if (*it == '-')
            ++it, sign = -1;
        else if (*it == '+')
            ++it;

        long long integer = 0;
        for (; it != str.end(); ++it) {
            if (*it >= '0' && *it <= '9')
                integer = 10 * integer + (*it - '0');
            else
                break;

            if (sign > 0 && integer >= MAX_ABS)
                return MAX_ABS;
            if (sign < 0 && integer > MAX_ABS)
                return -MAX_ABS - 1;
        }

        return integer * sign;
    }
    static constexpr int MAX_ABS = 0x7FFFFFFF;
};
