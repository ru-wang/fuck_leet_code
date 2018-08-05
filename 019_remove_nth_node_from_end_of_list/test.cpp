#include <initializer_list>

#include <catch2/catch.hpp>

#include "solution.hpp"

using namespace std;

/*
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 */

template<int remains, typename arg_t, typename... args_t>
struct append {
    static ListNode* impl(arg_t val, args_t... vals) {
        ListNode* l = new ListNode(val);
        l->next = append<sizeof...(args_t)-1, args_t...>::impl(vals...);
        return l;
    }
};

template<typename arg_t>
struct append<0, arg_t> {
    static ListNode* impl(arg_t val) {
        return new ListNode(val);
    }
};

template<typename... args_t>
ListNode* make_list(args_t... vals) {
    return append<sizeof...(args_t)-1, args_t...>::impl(vals...);
}

inline bool equal(
        const ListNode* list,
        const initializer_list<int>& ilist) {
    for (auto v : ilist) {
        if (list == nullptr || list->val != v)
            return false;
        list = list->next;
    }
    return (list == nullptr);
}

TEST_CASE("019_remove_nth_node_from_end_of_list", "[019]") {
    SECTION("example 1") {
        ListNode* head = make_list(1, 2);
        head = Solution().removeNthFromEnd(head, 2);
        head->print();
        CHECK(equal(head, {2}));
        delete head;
    }

    SECTION("example 2") {
        ListNode* head = make_list(1, 2, 3, 4, 5);
        head = Solution().removeNthFromEnd(head, 2);
        head->print();
        CHECK(equal(head, {1, 2, 3, 5}));
        delete head;
    }

    SECTION("example 3") {
        ListNode* head = make_list(1, 2, 3, 4, 5);
        head = Solution().removeNthFromEnd(head, 1);
        head->print();
        CHECK(equal(head, {1, 2, 3, 4}));
        delete head;
    }
}
