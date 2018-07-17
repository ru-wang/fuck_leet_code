#pragma once

#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows >= s.size() || numRows == 1)
            return s;

        std::string str;
        str.reserve(s.size());
        int period = numRows * 2 - 2;

        /* row == 0 */
        if (numRows > 0)
            for (int i = 0; i < s.size(); i += period)
                str.push_back(s[i]);

        /* row == [1...numRows - 2] */
        for (int row = 1; row <= numRows - 2; ++row) {
            for (int i = row, j = (numRows-1-row)*2; i < s.size(); i += period) {
                str.push_back(s[i]);
                if (i + j < s.size())
                    str.push_back(s[i + j]);
            }
        }

        /* row == numRows - 1 */
        if (numRows >= 2)
            for (int i = numRows - 1; i < s.size(); i += period)
                str.push_back(s[i]);

        return str;
    }
};
