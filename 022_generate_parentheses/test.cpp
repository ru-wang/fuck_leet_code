#include <unordered_set>

#include <catch2/catch.hpp>

#include "solution.hpp"

bool equal(const std::vector<std::string>& a,
           const std::unordered_set<std::string>& b) {
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
        if (b.count(a[i]) == 0)
            return false;
    return true;
}

TEST_CASE("022_generate_parentheses", "[022]") {
    CHECK(equal(Solution().generateParenthesis(3),
                { "((()))",
                  "(()())",
                  "(())()",
                  "()(())",
                  "()()()" }));

    CHECK(equal(Solution().generateParenthesis(0), { }));
}
