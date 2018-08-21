#pragma once

#include <cassert>
#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

template<typename ele_t>
void print(const std::vector<ele_t>& arr) {
    std::cout << "[ ";
    for (const auto& ele : arr)
        std::cout << ele << " ";
    std::cout << "]\n";
}

template<typename ele_t> class solution {
public:
    std::vector<ele_t> quick_sort(const std::vector<ele_t>& arr) {
        if (arr.empty()) return {};
        if (arr.size() == 1) return arr;
        if (arr.size() == 2)
            return (arr[0] > arr[1]) ?
                std::vector<ele_t>{arr[1], arr[0]} :
                std::vector<ele_t>{arr[0], arr[1]};
        std::vector<ele_t> sorted = arr;
        sort_recursive(sorted, 0, sorted.size() - 1);
        return sorted;
    }

private:
    void sort_recursive(std::vector<ele_t>& arr, const int i, const int j) {
        if (i >= j) {
            return;
        } else if (j - i == 1) {
            if (arr[i] > arr[j])
                std::swap(arr[i], arr[j]);
            return;
        }
        std::deque<ele_t> sorted(1, std::move(arr[i]));
        auto sep_it = sorted.begin();
        for (int k = i + 1; k <= j; ++k) {
            if (arr[k] <= *sep_it) {
                sorted.push_front(std::move(arr[k]));
            } else {
                sorted.push_back(std::move(arr[k]));
            }
        }
        int sep = i + sep_it - sorted.begin();
        for (int k = i; k <= j; ++k)
            std::swap(arr[k], sorted[k-i]);
        sort_recursive(arr, i, sep-1);
        sort_recursive(arr, sep+1, j);
    }
};
