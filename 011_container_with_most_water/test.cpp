#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("011_container_with_most_water", "[011]") {
    REQUIRE(Solution().maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49);
    REQUIRE(Solution().maxArea({1, 1}) == 1);
}
