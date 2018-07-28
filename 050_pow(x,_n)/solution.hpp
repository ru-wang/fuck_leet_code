#pragma once

#include <iostream>

/*
 *  -100.0 < x < 100.0
 *  n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 */
static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n == -1) return 1.0 / x;
        if (x == 0.0) return 0.0;

        if (n < 0)
            x = 1.0 / x;
        auto exp_max = (n > 0) ?
            static_cast<long long>(n) : -static_cast<long long>(n);
        double product = x, multiplicant = x;

        for (long long exp = 1, exp_inc = 1; exp < exp_max;) {
            if (exp_max - exp >= exp_inc) {
                product *= multiplicant;
                multiplicant *= multiplicant;
                exp += exp_inc;
                exp_inc *= 2;
            } else {
                multiplicant = x;
                exp_inc = 1;
            }
        }

        return product;
    }
};
