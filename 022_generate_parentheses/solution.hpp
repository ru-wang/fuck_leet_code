#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

struct node {
    node(char ch, int l, int r, node* p)
        : ch(ch), l_in_p(l), r_in_p(r), p(p) { }

    char ch;
    int l_in_p;
    int r_in_p;
    node* p;
    std::unique_ptr<node> c[2];
};

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n);
};

std::vector<std::string> Solution::generateParenthesis(int n)
{
    using namespace std;

    if (n == 0)
        return {};

    unique_ptr<node> root(new node(')', 1, 0, nullptr));
    vector<node*> lv { root.get() };

    for (int i = 1; i < n * 2; ++i) {
        vector<node*> next_lv;
        for (auto p : lv) {
            if (p->l_in_p < n) {
                auto l_c = new node(')', p->l_in_p+1, p->r_in_p, p);
                p->c[0].reset(l_c);
                next_lv.push_back(l_c);
            }
            if (p->r_in_p < p->l_in_p) {
                auto r_c = new node('(', p->l_in_p, p->r_in_p+1, p);
                p->c[1].reset(r_c);
                next_lv.push_back(r_c);
            }
        }
        lv = std::move(next_lv);
    }

    vector<string> strs;
    for (auto leaf : lv) {
        string str;
        while (leaf) {
            str.push_back(leaf->ch);
            leaf = leaf->p;
        }
        strs.push_back(std::move(str));
    }

    return strs;
}
