#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("007_reverse_integer", "[007]") {
    CHECK(Solution().reverse(0) == 0);
    CHECK(Solution().reverse(123) == 321);
    CHECK(Solution().reverse(-123) == -321);
    CHECK(Solution().reverse(120) == 21);
    CHECK(Solution().reverse(1200) == 21);
    CHECK(Solution().reverse(1200) == 21);
    CHECK(Solution().reverse(1200) == 21);
    CHECK(Solution().reverse(0x7FFFFFFF) == 0);
    CHECK(Solution().reverse(1-0x7FFFFFFF) == 0);
}
