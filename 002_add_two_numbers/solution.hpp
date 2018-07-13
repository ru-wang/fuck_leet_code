/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#pragma once

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        int carry = (sum >= 10) ? (sum %= 10, 1) : 0;
        auto head = new ListNode(sum);
        auto tail = head;
        while (l1->next || l2->next) {
            sum = carry;
            if (l1->next) sum += (l1 = l1->next)->val;
            if (l2->next) sum += (l2 = l2->next)->val;
            carry = (sum >= 10) ? (sum %= 10, 1) : 0;
            tail = tail->next = new ListNode(sum);
        }
        if (carry)
            tail = tail->next = new ListNode(1);
        return head;
    }
};
