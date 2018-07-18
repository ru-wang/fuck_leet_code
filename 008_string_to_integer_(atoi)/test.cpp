#include <catch2/catch.hpp>

#include <cstdlib>

#include "solution.hpp"

TEST_CASE("008_string_to_integer_(atoi)", "[008]") {
    CHECK(Solution().myAtoi("42") == 42);
    CHECK(Solution().myAtoi("   -42") == -42);
    CHECK(Solution().myAtoi("4193 with words") == 4193);
    CHECK(Solution().myAtoi("words and 987") == 0);
    CHECK(Solution().myAtoi("-91283472332") == -2147483648);
    CHECK(Solution().myAtoi("   +42") == 42);
    CHECK(Solution().myAtoi("2147483647") == 2147483647);
    CHECK(Solution().myAtoi("-2147483648") == -2147483648);
    CHECK(Solution().myAtoi("2147483648") == 2147483647);
    CHECK(Solution().myAtoi("-2147483649") == -2147483648);
}
