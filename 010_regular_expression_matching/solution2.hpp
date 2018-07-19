#pragma once

#include <functional>
#include <string>
#include <utility>
#include <vector>

void set_up_DFA_jumps(const std::string& pattern,
        std::vector<std::function<int(char)>>* DFA_jump) {
    std::vector<std::string> states {""};
    auto it = pattern.begin();
    while (it != pattern.end()) {
        char this_ch = *(it++);
        char next_ch = (it == pattern.end()) ? 0 : *(it++);
        if (next_ch == '*')
            states.push_back({this_ch, next_ch});
        else
            states.push_back({this_ch});
    }
}

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        if (s == p)    return true;
        if (p.empty()) return false;

        std::vector<std::function<int(char)>> DFA_jump;

        set_up_DFA_jumps(p, &DFA_jump);

        for (int i = 0, sid = 0; i <= s.size(); ++i) {
            char ch = (i == s.size()) ? 0 : s[i];
            sid = DFA_jump[sid](ch);
            if (sid == -1) return false;
        }

        return true;
    }
};
