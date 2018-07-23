#include <initializer_list>

#include <catch2/catch.hpp>

#include "solution.hpp"

/*
 *  Input:
 *  [
 *    1->4->5,
 *    1->3->4,
 *    2->6
 *  ]
 *  Output: 1->1->2->3->4->4->5->6
 */

template<int remains, typename arg, typename... args>
struct append {
    static ListNode* impl(arg val, args... vals) {
        ListNode* l = new ListNode(val);
        l->next = append<sizeof...(args)-1, args...>::impl(vals...);
        return l;
    }
};

template<typename arg>
struct append<0, arg> {
    static ListNode* impl(arg val) {
        return new ListNode(val);
    }
};

template<typename... args>
ListNode* make_list(args... vals) {
    return append<sizeof...(args)-1, args...>::impl(vals...);
}

void print_list(const ListNode* list) {
    if (list == nullptr)
        return;
    std::cout << list->val;
    while (list->next) {
        std::cout << "-->" << list->next->val;
        list = list->next;
    }
    std::cout << "\n";
}

inline bool equal(
        const ListNode* list,
        const std::initializer_list<int>& ilist) {
    for (auto v : ilist) {
        if (v != list->val)
            return false;
        list = list->next;
    }
    return (list == nullptr);
}

TEST_CASE("023_merge_k_sorted_lists", "[023]") {
    SECTION("023_01") {
        std::vector<ListNode*> lists {
            make_list(1, 4, 5),
            make_list(1, 3, 4),
            make_list(2, 6)
        };
        CHECK(equal(Solution().mergeKLists(lists), {1, 1, 2, 3, 4, 4, 5, 6}));
        if (lists.size())
            delete lists[0];
    }

    SECTION("[]") {
        std::vector<ListNode*> lists;
        CHECK(equal(Solution().mergeKLists(lists), {}));
    }

    SECTION("[[]]") {
        std::vector<ListNode*> lists {nullptr};
        CHECK(equal(Solution().mergeKLists(lists), {}));
    }

    SECTION("[][]") {
        std::vector<ListNode*> lists {nullptr, nullptr};
        CHECK(equal(Solution().mergeKLists(lists), {}));
    }
}
