#pragma once

#include <iostream>
#include <vector>

static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};
        if (nums.front() == target && nums.back() == target)
            return {0, (int)nums.size() - 1};
    }
};
