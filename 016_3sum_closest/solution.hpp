#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

int dist(int a, int b) {
    return (a < b) ? b - a : a - b;
}

class Solution {
public:
    int threeSumClosest(std::vector<int> nums, int target) {
        using namespace std;
        int closest = nums[0]+nums.back()+nums[nums.size()-2];
        sort(nums.begin(), nums.end());
        int min_dist = dist(target, closest);
        for (int k = 0; k < nums.size() - 2; ++k) {
            if (k > 0 && nums[k] == nums[k-1])
                continue;
            if (closest < target) {
                int max_sum = nums[k]+nums.back()+nums[nums.size()-2];
                if (max_sum < target && target - max_sum > min_dist)
                    continue;
            }
            if (closest > target) {
                int min_sum = nums[k]+nums[k+1]+nums[k+2];
                if (min_sum > target && min_sum - target > min_dist)
                    break;
            }
            for (int i = k + 1, j = nums.size() - 1; i < j;) {
                int sum = nums[k] + nums[i] + nums[j];
                int d = dist(sum, target);
                if (sum < target) {
                    ++i;
                    while (nums[i] == nums[i-1] && i < j) ++i;
                } else if (sum > target){
                    --j;
                    while (nums[j] == nums[j+1] && i < j) --j;
                } else {
                    return sum;
                }
                if (d < min_dist) {
                    min_dist = d;
                    closest = sum;
                }
            }
        }

        return closest;
    }
};
