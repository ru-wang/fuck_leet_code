#pragma once

#include <iostream>
#include <tuple>

struct ListNode {
    ListNode(int x) : val(x), next(nullptr) { }
    ~ListNode() { if (next) delete next; }

    void print() {
        ListNode* list = this;
        std::cout << list->val;
        while (list->next) {
            std::cout << "-->" << list->next->val;
            list = list->next;
        }
        std::cout << "\n";
    }

    int val;
    ListNode *next;
};

static auto ___ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

/*
 * return the reverse head and the next head
 */
inline std::tuple<ListNode*, ListNode*> reverse_k(ListNode* head, int k) {
    ListNode* cnode = head;
    for (int i = 1; i < k && cnode; ++i, cnode = cnode->next);
    if (cnode == nullptr)
        return std::make_tuple(head, nullptr);

    ListNode* next_head = cnode->next;
    ListNode* rev_head = cnode;

    ListNode* pnode = nullptr;
    cnode = head;
    ListNode* nnode = head->next;

    for (int i = 1; i < k; ++i) {
        pnode = cnode;
        cnode = nnode;
        nnode = cnode->next;
        cnode->next = pnode;
    }

    return std::make_tuple(rev_head, next_head);
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        using namespace std;
        if (k == 1) return head;
        if (head == nullptr) return nullptr;

        ListNode *rev_head = nullptr;
        ListNode* next_head = head;
        ListNode* prev_tail = head;
        tie(rev_head, next_head) = reverse_k(next_head, k);
        if (head == rev_head)
            return head;

        prev_tail->next = next_head;
        head = rev_head;

        while (next_head) {
            ListNode* tail = next_head;
            tie(rev_head, next_head) = reverse_k(next_head, k);
            prev_tail->next = rev_head;
            prev_tail = tail;
        }

        if (prev_tail != rev_head)
            prev_tail->next = nullptr;

        return head;
    }
};
