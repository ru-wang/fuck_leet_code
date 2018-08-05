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

TEST_CASE("025_reverse_nodes_in_k-group", "[025]") {
    SECTION("example 1") {
        ListNode* head = make_list(1, 2, 3, 4, 5);
        head = Solution().reverseKGroup(head, 1);
        head->print();
        CHECK(equal(head, {1, 2, 3, 4, 5}));
        delete head;
    }

    SECTION("example 2") {
        ListNode* head = make_list(1, 2, 3, 4, 5);
        head = Solution().reverseKGroup(head, 2);
        head->print();
        CHECK(equal(head, {2, 1, 4, 3, 5}));
        delete head;
    }

    SECTION("example 3") {
        ListNode* head = make_list(1, 2, 3, 4, 5);
        head = Solution().reverseKGroup(head, 3);
        head->print();
        CHECK(equal(head, {3, 2, 1, 4, 5}));
        delete head;
    }

    SECTION("example 4") {
        ListNode* head = make_list(1, 2, 3, 4, 5, 6, 7, 8);
        head = Solution().reverseKGroup(head, 3);
        head->print();
        CHECK(equal(head, {3, 2, 1, 6, 5, 4, 7, 8}));
        delete head;
    }

    SECTION("example 5") {
        ListNode* head = make_list(1, 2, 3, 4);
        head = Solution().reverseKGroup(head, 4);
        head->print();
        CHECK(equal(head, {4, 3, 2, 1}));
        delete head;
    }

    SECTION("example 6") {
        ListNode* head = make_list(1, 2, 3, 4, 5, 6, 7, 8);
        head = Solution().reverseKGroup(head, 4);
        head->print();
        CHECK(equal(head, {4, 3, 2, 1, 8, 7, 6, 5}));
        delete head;
    }

    SECTION("example 7") {
        ListNode* head = make_list(1, 2);
        head = Solution().reverseKGroup(head, 3);
        head->print();
        CHECK(equal(head, {1, 2}));
        delete head;
    }
}
