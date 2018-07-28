#include <cmath>
#include <catch2/catch.hpp>

#include "solution.hpp"

TEST_CASE("050_pow(x,_n)", "[050]") {
    CHECK(Solution().myPow(2.00000, 10) == Approx(pow(2.00000, 10)));
    CHECK(Solution().myPow(2.10000, 3)  == Approx(pow(2.10000, 3)));
    CHECK(Solution().myPow(2.00000, -2) == Approx(pow(2.00000, -2)));
    CHECK(Solution().myPow(2.00000, 0)  == Approx(pow(2.00000, 0)));
    CHECK(Solution().myPow(2.00000, 1)  == Approx(pow(2.00000, 1)));
    CHECK(Solution().myPow(2.00000, 9)  == Approx(pow(2.00000, 9)));
    CHECK(Solution().myPow(2.00000, 7)  == Approx(pow(2.00000, 7)));
    CHECK(Solution().myPow(2.00000, (int)-0x80000000)
            == Approx(pow(2.00000, (int)-0x80000000)));
}
