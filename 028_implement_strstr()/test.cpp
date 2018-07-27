#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("028_implement_strstr()", "[028]") {
    CHECK(Solution().strStr("hello", "ll")  == 2);
    CHECK(Solution().strStr("aaaaa", "bba") == -1);
    CHECK(Solution().strStr("aaaaa", "")    == 0);
    CHECK(Solution().strStr("", "")         == 0);
    CHECK(Solution().strStr("", "abc")      == -1);

    CHECK(Solution().strStr("bababac", "babac") == 2);
}
