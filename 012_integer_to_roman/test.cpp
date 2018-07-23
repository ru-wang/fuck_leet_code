#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("012_integer_to_roman", "[012]") {
    /* 3 */
    CHECK(Solution().intToRoman(3)    == "III");

    /* (5-1) */
    CHECK(Solution().intToRoman(4)    == "IV");

    /* (10-1) */
    CHECK(Solution().intToRoman(9)    == "IX");

    /* 50 + (5+3) */
    CHECK(Solution().intToRoman(58)   == "LVIII");

    /* 1000 + (1000-100) + (100-10) + (5-1) */
    CHECK(Solution().intToRoman(1994) == "MCMXCIV");

    /* 1000 + 500 + (100-10) + (5-1) */
    CHECK(Solution().intToRoman(1594) == "MDXCIV");

    /* 1000 + 100 + (100-10) + 0 */
    CHECK(Solution().intToRoman(1190) == "MCXC");

    /* 1000 + (500-100) + (50-10) + (5-1) */
    CHECK(Solution().intToRoman(1444) == "MCDXLIV");
}
