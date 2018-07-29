#include <catch2/catch.hpp>

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

TEST_CASE("016_3sum_closest", "[016]") {
    CHECK(Solution().threeSumClosest({-1, 2, 1, -4}, 1) == 2);
}
