#pragma once

#include <iostream>
#include <vector>

namespace {

struct ListNode {
    ListNode(int x) : val(x), next(nullptr) { }

    ~ListNode() { if (next) delete next; }

    int val;
    ListNode *next;
};

}

static auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

inline ListNode* make_list(std::vector<ListNode*> vec) {
    if (vec.empty())
        return nullptr;
    for (int i = 0; i < vec.size() - 1; ++i)
        vec[i]->next = vec[i+1];
    vec.back()->next = nullptr;
    return vec.front();
}

ListNode* merge_two(ListNode* a, ListNode* b) {
    std::vector<ListNode*> vec;
    while (a && b) {
        if (a->val <= b->val)
            vec.push_back(a), a = a->next;
        else
            vec.push_back(b), b = b->next;
    }
    while (a) vec.push_back(a), a = a->next;
    while (b) vec.push_back(b), b = b->next;
    return make_list(vec);
}

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        for (int k = lists.size(); k != 1; k = (k+1)/2)
            for (int i = 0; i < k/2; ++i)
                lists[i] = merge_two(lists[i], lists[k-i-1]);
        return lists[0];
    }
};
