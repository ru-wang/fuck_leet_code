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
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        using namespace std;

        switch (nums.size()) {
            case 0:
            case 1:
            case 2:
            case 3: return { };
            case 4: if (nums[0] + nums[1] + nums[2] + nums[3] == target)
                        return { nums };
                    else
                        return { };
        }

        int n = nums.size();
        vector<vector<int>> quadruples;
        sort(nums.begin(), nums.end());

        if (nums[n-1] + nums[n-2] + nums[n-3] + nums[n-4] < target)
            return { };
        if (nums[0] + nums[1] + nums[2] + nums[3] > target)
            return { };

        for (int i_0 = 0; i_0 < n - 3; ++i_0) {
            if (i_0 > 0 && nums[i_0] == nums[i_0 - 1])
                continue;
            int res_0 = target - nums[i_0];
            if (nums[n-1] + nums[n-2] + nums[n-3] < res_0)
                continue;
            if (nums[i_0+1] + nums[i_0+2] + nums[i_0+3] > res_0)
                break;

            /* compute 3 sum */
            for (int i_1 = i_0 + 1; i_1 < n - 2; ++i_1) {
                if (i_1 > i_0 + 1 && nums[i_1] == nums[i_1 - 1])
                    continue;
                int res_0_1 = res_0 - nums[i_1];
                if (nums[n-1] + nums[n-2] < res_0_1)
                    continue;
                if (nums[i_1+1] + nums[i_1+2] > res_0_1)
                    break;
                for (int i_2 = i_1 + 1, i_3 = n - 1; i_2 < i_3; ) {
                    int sum_2_3 = nums[i_2] + nums[i_3];
                    if (sum_2_3 < res_0_1) {
                        ++i_2;
                        while (nums[i_2] == nums[i_2 - 1] && i_2 < i_3)
                            ++i_2;
                    } else if (sum_2_3 > res_0_1) {
                        --i_3;
                        while (nums[i_3] == nums[i_3 + 1] && i_2 < i_3)
                            --i_3;
                    } else {
                        quadruples.push_back({nums[i_0], nums[i_1], nums[i_2], nums[i_3]});
                        ++i_2;
                        while (nums[i_2] == nums[i_2 - 1] && i_2 < i_3)
                            ++i_2;
                        --i_3;
                        while (nums[i_3] == nums[i_3 + 1] && i_2 < i_3)
                            --i_3;
                    }
                }
            }
        }

        return quadruples;
    }
};
