#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        using namespace std;
        if (nums.size() < 3)
            return {};
        if (nums.size() == 3)
            return (nums[0] + nums[1] + nums[2] == 0) ?
                vector<vector<int>>{ nums } : vector<vector<int>>{};
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for (int k = 0; k < nums.size() - 2; ++k) {
            if (k > 0 && nums[k] == nums[k-1])
                continue;
            if (nums[k] + nums[k+1] + nums[k+2] > 0)
                break;

            int res = -nums[k];
            if (nums[nums.size() - 1] + nums[nums.size() - 2] < res)
                continue;

            for (int i = k + 1, j = nums.size() - 1; i < j;) {
                int two_sum = nums[i] + nums[j];
                if (two_sum < res) {
                    ++i;
                    while (nums[i] == nums[i-1] && i < j)
                        ++i;
                } else if (two_sum > res) {
                    --j;
                    while (nums[j] == nums[j+1] && i < j)
                        --j;
                } else {
                    triplets.push_back({nums[k], nums[i], nums[j]});
                    ++i;
                    while (nums[i] == nums[i-1] && i < j)
                        ++i;
                    --j;
                    while (nums[j] == nums[j+1] && i < j)
                        --j;
                }
            }
        }
        return triplets;
    }
};
