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
    int search(const std::vector<int>& nums, int target) {
        using namespace std;
        if (nums.empty()) return -1;
        if (nums.size() <= 3) {
            for (int i = 0; i < nums.size(); ++i)
                if (nums[i] == target)
                    return i;
            return -1;
        }
        if (target == nums.front())
            return 0;
        if (target == nums.back())
            return nums.size() - 1;
        if (target < nums.front() && target > nums.back())
            return -1;
        int i = 0, j = nums.size() - 1;
        int k = 0;
        if (nums[i] > nums[j]) {
            while (i < j) {
                k = (i + j) / 2;
                if (nums[k] > nums[k+1])
                    break;
                else if (nums[k] > nums[i])
                    i = k;
                else
                    j = k;
            }
            if (target < nums[k+1] || target > nums[k])
                return -1;
            if (target <= nums[k] && target >= nums.front())
                i = 0, j = k;
            else if (target >= nums[k+1] && target <= nums.back())
                i = k + 1, j = nums.size() - 1;
        }
        while (i < j) {
            if (target == nums[i])
                return i;
            if (target == nums[j])
                return j;
            k = (i + j) / 2;
            if (target <= nums[k])
                j = k;
            else
                i = k + 1;
        }
        return -1;
    }
};
