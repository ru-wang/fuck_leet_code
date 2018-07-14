#include "solution.hpp"

#include <array>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    while (true) {
        std::array<std::vector<int>, 2> arrs;
        for (int i = 0; i < 2; ++i) {
            std::string str;
            auto& arr = arrs[i];
            while (std::cin >> str) {
                try {
                    arr.push_back(std::stoi(str));
                } catch(std::invalid_argument) {
                    break;
                }
            }
        }

        std::cout << "parse:\n";
        for (auto v : arrs[0])
            std::cout << v << " ";
        std::cout << "\n";
        for (auto v : arrs[1])
            std::cout << v << " ";
        std::cout << "\nmedian: "
                  << Solution().findMedianSortedArrays(arrs[0], arrs[1])
                  << std::endl;
    }
    return 0;
}
