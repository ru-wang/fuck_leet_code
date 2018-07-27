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
    int divide(int dividend, int divisor) {
        if (dividend == INTEGER_MIN && divisor == -1)
            return INTEGER_MAX;

        if (dividend == 0)  return 0;
        if (divisor  == 1)  return dividend;
        if (divisor  == -1) return -dividend;

        bool positive = true;
        if ((dividend > 0 && divisor < 0) ||
            (dividend < 0 && divisor > 0))
            positive = false;

        const long long abs_x = dividend > 0 ?
            dividend : -static_cast<long long>(dividend);
        const long long abs_y = divisor > 0  ?
            divisor  : -static_cast<long long>(divisor);

        long long x = abs_x, y = abs_y, q = 0, q_inc = 1;
        while (x >= abs_y) {
            if (x >= y) {
                q += q_inc;
                x -= y;
                y <<= 1;
                q_inc <<= 1;
            } else {
                y = abs_y;
                q_inc = 1;
            }
        }

        return (positive ? q : -q);
    }

    static const int INTEGER_MAX = 0x7FFFFFFF;
    static const int INTEGER_MIN = -0x80000000;
};
