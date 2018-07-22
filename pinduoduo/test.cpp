#include <catch2/catch.hpp>

#include "cool_number.hpp"

TEST_CASE("cool number", "[pinduoduo]") {
    CHECK(solution().cool_number(5, "787585") == std::make_tuple(4, "777577"));
}
