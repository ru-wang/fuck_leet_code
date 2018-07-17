#pragma once

class Solution {
public:
    int reverse(int x) {
        long long a = x > 0 ? x : -x;
        long long b = 0;
        while (a > 0) {
            b = b * 10 + a % 10;
            a /= 10;
        }
        if (b > MAX || b < MIN)
            return 0;
        else if (x < 0)
            return -b;
        else
            return b;
    }
    static constexpr int MAX = 0x7FFFFFFF;
    static constexpr int MIN = -MAX + 1;
};
