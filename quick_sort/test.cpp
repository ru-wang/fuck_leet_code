#include <initializer_list>
#include <memory>
#include <catch2/catch.hpp>

#include "solution.hpp"

template<typename ele_t>
bool equal(const std::vector<ele_t>& a,
           const std::vector<ele_t>& b) {
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
         if (a[i] != b[i])
             return false;
    return true;
}

TEST_CASE("quick sort", "[qsort]") {
    CHECK(equal(solution<int>().quick_sort({}), {}));
    CHECK(equal(solution<int>().quick_sort({1}), {1}));
    CHECK(equal(solution<int>().quick_sort({3, 2}), {2, 3}));
    CHECK(equal(solution<int>().quick_sort({5, 4, 2, 3, 4, 1}), {1, 2, 3, 4, 4, 5}));
    CHECK(equal(solution<int>().quick_sort({7, 2, 3, 13, 11, 19, 17, 5}), {2, 3, 5, 7, 11, 13, 17, 19}));
}
