#include <catch2/catch.hpp>

#include "solution.hpp"

void print(const std::vector<std::string> strs) {
    std::cout << "{ ";
    for (const auto& str : strs)
        std::cout << str << " ";
    std::cout << "}" << std::endl;
}

bool equal(std::vector<std::string> a,
        std::vector<std::string> b) {
    print(a);
    print(b);
    if (a.size() != b.size()) return false;
    for (int i = a.size() - 1; i >= 0; --i) {
        for (auto it = b.begin(); it != b.end(); ++it) {
            if (a[i] == *it) {
                b.erase(it);
                break;
            }
        }
        a.pop_back();
        if (a.size() != b.size())
            return false;
    }
    return true;
}

TEST_CASE("017_letter_combinations_of_a_phone_number", "[017]") {
    CHECK(equal(Solution().letterCombinations("29"),
            { "aw", "ax", "ay", "az",
              "bw", "bx", "by", "bz",
              "cw", "cx", "cy", "cz" }));

    CHECK(equal(Solution().letterCombinations("23"),
            { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }));
    CHECK(equal(Solution().letterCombinations(""), { }));
}
