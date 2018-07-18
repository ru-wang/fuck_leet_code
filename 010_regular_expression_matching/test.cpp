#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("010_regular_expression_matching", "[010]") {
    CHECK(Solution().isMatch("aa", "a") == false);
    CHECK(Solution().isMatch("aa", "a*") == true);
    CHECK(Solution().isMatch("ab", ".*") == true);
    CHECK(Solution().isMatch("aab", "c*a*b") == true);
    CHECK(Solution().isMatch("mississippi", "mis*is*p*.") == false);

    CHECK(Solution().isMatch("b", "c*a*b") == true);
    CHECK(Solution().isMatch("ab", "c*a*b") == true);

    CHECK(Solution().isMatch("accab", "a.*ab") == true);
    CHECK(Solution().isMatch("acab", "a.*ab") == true);
    CHECK(Solution().isMatch("cab", ".*ab") == true);
    CHECK(Solution().isMatch("ab", ".*ab") == true);
    CHECK(Solution().isMatch("", ".*") == true);

    CHECK(Solution().isMatch("acac", "a.*ab") == false);
}
