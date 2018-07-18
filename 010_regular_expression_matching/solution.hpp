#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

struct DFA {
    DFA(const std::string& pattern) {
        char prev_ch = -1;
        std::function<int(char, int)> jump;
        for (int i = 0; i < pattern.size(); ++i) {
            char this_ch = pattern[i];
            char next_ch = (i+1 < pattern.size()) ? pattern[i+1] : 0;

            if (next_ch != '*') {
                if (this_ch >= 'a' && this_ch <= 'z') {
                    jump = [=](char input, int id) { return (input==this_ch)?++id:-1; };
                    state_jumps.push_back(std::move(jump));
                } else if (this_ch == '.') {
                    jump = [=](char, int id) { return ++id; };
                    state_jumps.push_back(std::move(jump));
                } else if (this_ch == '*') {
                    jump = [=](char input, int id) {
                        if (prev_ch == '.') return id;
                        if (input == prev_ch) return id;
                        return ++id;
                    };
                }
            } else {
                if (this_ch == '.')
                    jump = [=](char, int id) { return id; };
                else
                    jump = [=](char input, int id) { return (input==this_ch)?id:++id; };
                state_jumps.push_back(std::move(jump));
            }

            prev_ch = this_ch;
        }
        state_jumps.emplace_back([](char, int) { return -1; });
    }

    int state_id = 0;
    std::vector<std::function<int(char, int)>> state_jumps;
};


class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        if (s == p)    return true;
        if (p.empty()) return false;
        DFA dfa(p);
        int i = 0;
        for (;i < s.size() && dfa.state_id != -1; ++i)
            dfa.state_id = dfa.state_jumps[dfa.state_id](s[i], dfa.state_id);
        return (i == s.size());
    }
};
