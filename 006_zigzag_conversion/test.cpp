#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("006_zigzag_conversion", "[006]") {
    CHECK(Solution().convert("", 3) == "");
    CHECK(Solution().convert("AB", 1) == "AB");
    CHECK(Solution().convert("PAYPALISHIRING", 0) == "");
    CHECK(Solution().convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    CHECK(Solution().convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    CHECK(Solution().convert("PAYPALISHIRING", 14) == "PAYPALISHIRING");
}
