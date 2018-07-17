#include "solution.hpp"

#include <iostream>

int main() {
    while (true) {
        std::string str;
        std::cout << "input : ";
        std::cin >> str;
        std::cout << "output: "
                  << Solution().longestPalindrome(str)
                  << std::endl;
    }
    return 0;
}
