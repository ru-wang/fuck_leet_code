#include <catch2/catch.hpp>

#include <cstdlib>

#include "solution.hpp"

TEST_CASE("008_string_to_integer_(atoi)") {
    REQUIRE(Solution().myAtoi("42") == 42);
    REQUIRE(Solution().myAtoi("   -42") == -42);
    REQUIRE(Solution().myAtoi("4193 with words") == 4193);
    REQUIRE(Solution().myAtoi("words and 987") == 0);
    REQUIRE(Solution().myAtoi("-91283472332") == -2147483648);
    REQUIRE(Solution().myAtoi("   +42") == 42);
    REQUIRE(Solution().myAtoi("2147483647") == 2147483647);
    REQUIRE(Solution().myAtoi("-2147483648") == -2147483648);
    REQUIRE(Solution().myAtoi("2147483648") == 2147483647);
    REQUIRE(Solution().myAtoi("-2147483649") == -2147483648);
}
