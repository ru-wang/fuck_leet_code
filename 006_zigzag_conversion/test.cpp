#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("006_zigzag_conversion") {
    REQUIRE(Solution().convert("", 3) == "");
    REQUIRE(Solution().convert("AB", 1) == "AB");
    REQUIRE(Solution().convert("PAYPALISHIRING", 0) == "");
    REQUIRE(Solution().convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    REQUIRE(Solution().convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    REQUIRE(Solution().convert("PAYPALISHIRING", 14) == "PAYPALISHIRING");
}
