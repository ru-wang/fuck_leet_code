
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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode before_head(0);
        before_head.next = head;
        ListNode* last = &before_head;
        while (last && last->next) {
            last->next = swap(last->next);
            last = last->next->next;
        }
        ListNode* new_head = before_head.next;
        before_head.next = nullptr;
        return new_head;
    }

    ListNode* swap(ListNode* e) const {
        if (e->next == nullptr)
            return e;
        ListNode* e1 = e;
        ListNode* e2 = e->next;
        e1->next = e2->next;
        e2->next = e1;
        return e2;
    }
};
