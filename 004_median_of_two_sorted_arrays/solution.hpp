#pragma once

#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1 + len2;
        if (nums1.empty())
            return (nums2[len2/2]+nums2[(len2+1)/2-1])*0.5;
        if (nums2.empty())
            return (nums1[len1/2]+nums1[(len1+1)/2-1])*0.5;

        std::vector<int> merged;
        int i = 0, j = 0;
        while (true) {
            if (nums1[i] <= nums2[j])
                merged.push_back(nums1[i++]);
            else
                merged.push_back(nums2[j++]);

            if (merged.size() > total / 2)
                return (merged[total/2]+merged[(total+1)/2-1])*0.5;

            if (i == nums1.size()) {
                int remains = total / 2 - merged.size();
                int id = remains + j;
                if ((len1 + len2) % 2) {
                    return nums2[id];
                } else {
                    if (remains == 0)
                        return (nums2[id]+merged.back())*0.5;
                    else
                        return (nums2[id]+nums2[id-1])*0.5;
                }
            }

            if (j == nums2.size()) {
                int remains = total / 2 - merged.size();
                int id = remains + i;
                if ((len1 + len2) % 2) {
                    return nums1[id];
                } else {
                    if (remains == 0)
                        return (nums1[id]+merged.back())*0.5;
                    else
                        return (nums1[id]+nums1[id-1])*0.5;
                }
            }
        }
    }
};
