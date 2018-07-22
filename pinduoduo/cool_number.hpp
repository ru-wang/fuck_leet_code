#pragma once

#include <algorithm>
#include <limits>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>

struct num_info {
    num_info(int num) : num(num) { }

    void add(int id, int cost) {
        costs.emplace_back(id, cost);
        total_cost += std::abs(cost);
    }

    void sort() {
        std::sort(costs.begin(), costs.end(),
                [](const std::pair<int, int>& a,
                   const std::pair<int, int>& b) {
                    if (std::abs(a.second) < std::abs(b.second))
                        return true;
                    if (std::abs(a.second) > std::abs(b.second))
                        return false;
                    if (a.second < b.second)
                        return true;
                    return a.first > b.first;
                });
    }

    std::vector<std::pair<int, int>> costs;
    int total_cost = 0;
    int change_bit_num = 0;
    int num;
};

class solution {
public:
    std::tuple<int, std::string> cool_number(int k, const std::string& input_str) {
        using namespace std;

        int n = input_str.size();
        unordered_map<int, num_info> table;
        for (int i = 0; i < input_str.size(); ++i) {
            int num_i = input_str[i] - '0';
            auto ret = table.emplace(num_i, num_i);
            if (ret.second == false)
                continue;
            auto& info = ret.first->second;
            for (int j = 0; j < n; ++j) {
                int num_j = input_str[j] - '0';
                int cost = num_j - num_i;
                if (cost != 0)
                    info.add(j, cost);
            }
            info.change_bit_num = k - (n - info.costs.size());
            info.sort();
            while (info.costs.size() > info.change_bit_num) {
                info.total_cost -= std::abs(info.costs.back().second);
                info.costs.pop_back();
            }
        }

        string min_number;
        int min_cost = std::numeric_limits<int>::max();
        for (auto& entry : table) {
            int num = entry.first;
            auto& info = entry.second;
            if (info.total_cost < min_cost) {
                min_cost = info.total_cost;
                min_number = input_str;
                for (auto& e : info.costs)
                    min_number[e.first] = num + '0';
            } else if (info.total_cost == min_cost) {
                string number = input_str;
                for (auto& e : info.costs)
                    number[e.first] = num + '0';
                if (number < min_number)
                    min_number = number;
            }
        }

        return make_tuple(min_cost, min_number);
    }
};
