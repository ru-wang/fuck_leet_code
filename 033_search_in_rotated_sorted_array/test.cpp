#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("033_search_in_rotated_sorted_array", "[033]") {
    CHECK(Solution().search({1,2,3,4,5,6,7}, 0) == -1);
    CHECK(Solution().search({1,2,3,4,5,6,7}, 3) == 2);
    CHECK(Solution().search({4,5,6,7,0,1,2}, 0) == 4);
    CHECK(Solution().search({4,5,6,7,0,1,2}, 3) == -1);
}
