#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

unsigned int factorial(unsigned int number)
{
    return (number <= 1) ? number : factorial(number-1)*number;
}

TEST_CASE("catch2", "[CATCH2]")
{
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(10) == 3628800);
}
