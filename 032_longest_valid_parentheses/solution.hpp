#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>

static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int longestValidParentheses(std::string s) {
        using namespace std;

        if (s.size() < 2) return 0;

        int i = 0;
        while (i < s.size() && s[i] == ')') ++i;

        int longest = 0;
        vector<pair<int, int>> paired;
        vector<int> pstack;
        pstack.reserve(s.size() - i);
        paired.reserve(pstack.size() / 2);
        for (; i < s.size(); ++i) {
            switch (s[i]) {
                case '(': pstack.push_back(i);
                          break;
                case ')': if (not pstack.empty()) {
                              auto new_paired = make_pair(pstack.back(), i);
                              pstack.pop_back();
                              while (not paired.empty()) {
                                  if (new_paired.first == paired.back().second + 1) {
                                      /* merge */
                                      new_paired.first = paired.back().first;
                                      paired.pop_back();
                                  } else if (new_paired.first == paired.back().first - 1) {
                                      /* merge */
                                      paired.pop_back();
                                  } else {
                                      break;
                                  }
                              }
                              int len  = new_paired.second - new_paired.first + 1;
                              longest = (len > longest) ? len : longest;
                              paired.push_back(move(new_paired));
                          }
                default:  break;
            }
        }
        return longest;
    }
};
