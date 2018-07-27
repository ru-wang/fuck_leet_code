#include <catch2/catch.hpp>

#include <limits>

#include "solution.hpp"

TEST_CASE("029_divide_two_integers", "[029]") {
    CHECK(Solution().divide(7, -3) == 7 / -3);
    CHECK(Solution().divide(8, 2)  == 8 / 2);
    CHECK(Solution().divide(10, 3) == 10 / 3);
    CHECK(Solution().divide(16, 2) == 16 / 2);
    CHECK(Solution().divide(-10, 2) == -10 / 2);
    CHECK(Solution().divide(-2147483647, 2) == -2147483647 / 2);
    CHECK(Solution().divide(-2147483648, 2) == -2147483648 / 2);

    CHECK(Solution().divide(
                std::numeric_limits<int>::min(), -1) ==
                std::numeric_limits<int>::max());

    CHECK(Solution().divide(
                std::numeric_limits<int>::max(), 1) ==
                std::numeric_limits<int>::max());

    CHECK(Solution().divide(
                std::numeric_limits<int>::max(), 2) ==
                std::numeric_limits<int>::max() / 2);

    CHECK(Solution().divide(
                std::numeric_limits<int>::min(), 2) ==
                std::numeric_limits<int>::min() / 2);
}
