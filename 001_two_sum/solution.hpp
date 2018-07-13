#pragma once

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> complete;
        complete[target - nums[0]] = 0;
        for (int i = 1; i < nums.size(); ++i) {
            auto entry = complete.find(nums[i]);
            if (entry != complete.end())
                return {entry->second, i};
            complete[target - nums[i]] = i;
        }
        return {};
    }
};
