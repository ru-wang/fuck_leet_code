#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("007_reverse_integer") {
    REQUIRE(Solution().reverse(0) == 0);
    REQUIRE(Solution().reverse(123) == 321);
    REQUIRE(Solution().reverse(-123) == -321);
    REQUIRE(Solution().reverse(120) == 21);
    REQUIRE(Solution().reverse(1200) == 21);
    REQUIRE(Solution().reverse(1200) == 21);
    REQUIRE(Solution().reverse(1200) == 21);
    REQUIRE(Solution().reverse(0x7FFFFFFF) == 0);
    REQUIRE(Solution().reverse(1-0x7FFFFFFF) == 0);
}
