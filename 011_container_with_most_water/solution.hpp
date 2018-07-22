#pragma once

#include <vector>

class Solution {
public:
    int maxArea(const std::vector<int>& h) {
        int l = 0, r = h.size() - 1, w = r, max = 0;
        while (l < r) {
            int capacity = w-- * (h[l] < h[r] ? h[l] : h[r]);
            max = max > capacity ? max : capacity;
            if (h[l] < h[r])
                ++l;
            else
                --r;
        }
        return max;
    }
};
