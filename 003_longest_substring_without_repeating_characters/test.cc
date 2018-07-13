#include "solution.hpp"

#include <iostream>

int main() {
    while (true) {
        std::string str;
        std::cin >> str;
        std::cout << Solution().lengthOfLongestSubstring(str) << std::endl;
    }
    return 0;
}

