#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("009_palindrome_number") {
    REQUIRE(Solution().isPalindrome(0) == true);
    REQUIRE(Solution().isPalindrome(121) == true);
    REQUIRE(Solution().isPalindrome(-121) == false);
    REQUIRE(Solution().isPalindrome(10) == false);
}
