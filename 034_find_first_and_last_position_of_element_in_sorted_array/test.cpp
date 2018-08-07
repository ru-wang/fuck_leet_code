#include <initializer_list>

#include <catch2/catch.hpp>

#include "solution.hpp"

inline bool equal(
        const std::vector<int>& a, const std::initializer_list<int>& b) {
    if (a.size() != b.size())
        return false;
    for (auto it = b.begin(); it != b.end(); ++it)
        if (*it != a[it - b.begin()])
            return false;
    return true;
}

TEST_CASE("034_find_first_and_last_position_of_element_in_sorted_array", "[034]") {
    CHECK(equal(Solution().searchRange({5,7,7,8,8,10}, 8), {3,4}));
    CHECK(equal(Solution().searchRange({5,7,7,8,8,10}, 6), {-1, -1}));
    CHECK(equal(Solution().searchRange({5,7,7,8,8,10}, 5), {0, 0}));
}
