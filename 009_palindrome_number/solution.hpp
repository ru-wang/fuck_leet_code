#pragma once

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0)      return true;
        if (x < 0)       return false;
        if (x % 10 == 0) return false;
        long long rev = 0;
        long long y = x;
        while (y > 0) {
            rev = rev * 10 + y % 10;
            y /= 10;
        }
        return (rev == x);
    }
};
