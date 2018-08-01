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

template<typename ele_t>
bool equal(std::vector<ele_t> a,
        std::vector<ele_t> b) {
    if (a.size() != b.size()) return false;
    for (int i = a.size() - 1; i >= 0; --i) {
        for (auto it = b.begin(); it != b.end(); ++it) {
            if (a[i] == *it) {
                b.erase(it);
                break;
            }
        }
        a.pop_back();
        if (a.size() != b.size())
            return false;
    }
    return true;
}

template<typename ele_t>
bool equal(std::vector<std::vector<ele_t>> a,
        std::vector<std::vector<ele_t>> b) {
    if (a.size() != b.size()) return false;
    for (int i = a.size() - 1; i >= 0; --i) {
        for (auto it = b.begin(); it != b.end(); ++it) {
            if (equal(a[i], *it)) {
                b.erase(it);
                break;
            }
        }
        a.pop_back();
        if (a.size() != b.size())
            return false;
    }
    return true;
}

TEST_CASE("018_4sum", "[018]") {
    std::vector<int> arr{1, 0, -1, 0, -2, 2};
    CHECK(equal(Solution().fourSum(arr, 0),
            { {-1, 0, 0, 1}, {-2, -1, 1, 2}, {-2,  0, 0, 2} }));
}
