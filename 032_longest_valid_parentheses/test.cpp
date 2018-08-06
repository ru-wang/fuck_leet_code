#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("032_longest_valid_parentheses", "[032]") {
    CHECK(Solution().longestValidParentheses("(")             == 0);
    CHECK(Solution().longestValidParentheses(")(")            == 0);
    CHECK(Solution().longestValidParentheses("()")            == 2);
    CHECK(Solution().longestValidParentheses("(()")           == 2);
    CHECK(Solution().longestValidParentheses(")()())")        == 4);
    CHECK(Solution().longestValidParentheses(")(()())")       == 6);
    CHECK(Solution().longestValidParentheses(")()())((()))")  == 6);
    CHECK(Solution().longestValidParentheses(")()())((()))(") == 6);
    CHECK(Solution().longestValidParentheses(")(()()()))")    == 8);
    CHECK(Solution().longestValidParentheses(")(()()()))")    == 8);
    CHECK(Solution().longestValidParentheses("(((()))")       == 6);
    CHECK(Solution().longestValidParentheses("()(()")         == 2);
    CHECK(Solution().longestValidParentheses("()((((()")      == 2);
    CHECK(Solution().longestValidParentheses("(()(((((()")    == 2);
}
