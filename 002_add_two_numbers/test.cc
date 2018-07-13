#include "solution.hpp"

#include <iostream>

/**
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

int main() {
    while (true) {
        char ch;
        auto head1 = new ListNode(0);
        auto head2 = new ListNode(0);
        auto head = head1;
        while (std::cin >> ch) {
            if (ch >= '0' && ch <= '9')
                head = head->next = new ListNode(ch - '0');
            else if (ch == '$')
                break;
            else
                head = head2;
        }
        for (auto node = Solution().addTwoNumbers(head1->next, head2->next);
             node; node = node->next)
            std::cout << node->val;
        std::cout << std::endl;
    }
    return 0;
}
