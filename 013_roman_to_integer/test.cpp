#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("013_roman_to_integer", "[013]") {
    CHECK(Solution().romanToInt("III")     == 3);
    CHECK(Solution().romanToInt("IV")      == 4);
    CHECK(Solution().romanToInt("IX")      == 9);
    CHECK(Solution().romanToInt("LVIII")   == 58);
    CHECK(Solution().romanToInt("MCMXCIV") == 1994);
    CHECK(Solution().romanToInt("")        == 0);
    CHECK(Solution().romanToInt("I")       == 1);
}
