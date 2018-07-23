#pragma once

#include <iostream>
#include <string>
#include <vector>

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
    /* 0 < num < 4000 */
    std::string intToRoman(int num) {
        using namespace std;

        char table[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' }; 

        int offset = 0;
        vector<char> inv;
        inv.reserve(8);
        while (num > 0) {
            int bit = num % 10;
            switch (bit) {
                case 9:
                    inv.push_back(table[offset+2]);
                    inv.push_back(table[offset+0]); break;
                case 8:
                    inv.push_back(table[offset+0]);
                case 7:
                    inv.push_back(table[offset+0]);
                case 6:
                    inv.push_back(table[offset+0]);
                case 5:
                    inv.push_back(table[offset+1]); break;
                case 4:
                    inv.push_back(table[offset+1]);
                    inv.push_back(table[offset+0]); break;
                case 3:
                    inv.push_back(table[offset+0]);
                case 2:
                    inv.push_back(table[offset+0]);
                case 1:
                    inv.push_back(table[offset+0]);
                case 0:
                    break;
            }
            num /= 10;
            offset += 2;
        }
        return string(inv.rbegin(), inv.rend());
    }
};
