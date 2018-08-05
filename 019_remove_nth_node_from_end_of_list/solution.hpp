#pragma once

#include <iostream>

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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        using namespace std;

        int len = 0;
        ListNode* node = head;
        while (node) {
            ++len;
            node = node->next;
        }

        ListNode* del = nullptr;
        if (len == n) {
            del = head;
            head = del->next;
            del->next = nullptr;
        } else {
            node = head;
            for (int i = 0; i < len - n - 1; ++i)
                node = node->next;
            del = node->next;
            node->next = del->next;
            del->next = nullptr;
        }
        delete del;

        return head;
    }
};
