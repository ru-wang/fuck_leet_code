#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("009_palindrome_number", "[009]") {
    CHECK(Solution().isPalindrome(0) == true);
    CHECK(Solution().isPalindrome(121) == true);
    CHECK(Solution().isPalindrome(-121) == false);
    CHECK(Solution().isPalindrome(10) == false);
}
