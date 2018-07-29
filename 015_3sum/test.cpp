#include <catch2/catch.hpp>

#include <initializer_list>
#include <unordered_set>

#include "solution.hpp"

/*
 *  Given array nums = [-1, 0, 1, 2, -1, -4],
 *
 *  A solution set is:
 *  [
 *    [-1, 0, 1],
 *    [-1, -1, 2]
 *  ]
 */

bool equal(std::vector<int> a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;

    for (int i = a.size() - 1; i >= 0; --i) {
        for (auto v : b) {
            if (a[i] == v) {
                a.pop_back();
                break;
            }
        }
        if (a.size() != i)
            return false;
    }

    return true;
}

bool equal(std::vector<std::vector<int>> a,
        const std::vector<std::vector<int>>& b) {
    if (a.size() != b.size()) return false;

    for (int i = a.size() - 1; i >= 0; --i) {
        for (const auto& tb : b) {
            if (equal(a[i], tb)) {
                a.pop_back();
                break;
            }
        }
        if (a.size() != i)
            return false;
    }
    return true;
}

TEST_CASE("015_3sum", "[015]") {
    std::vector<int> arr{-1, 0, 1, 2, -1, -4};
    CHECK(equal(Solution().threeSum(arr), { {-1, 0, 1}, {-1, -1, 2} }));
}
