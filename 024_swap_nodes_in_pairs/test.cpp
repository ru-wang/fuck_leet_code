#include <memory>
#include <catch2/catch.hpp>
#include "solution.hpp"

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

TEST_CASE("024_swap_nodes_in_pairs", "[024]") {
    CHECK(equal(Solution().swapPairs(nullptr), {}));
    CHECK(equal(Solution().swapPairs(
            make_list(1)), {1}));
    CHECK(equal(Solution().swapPairs(
            make_list(1, 2)), {2, 1}));
    CHECK(equal(Solution().swapPairs(
            make_list(1, 2)), {2, 1}));
    CHECK(equal(Solution().swapPairs(
            make_list(1, 2, 3)), {2, 1, 3}));
    CHECK(equal(Solution().swapPairs(
            make_list(1, 2, 3, 4)), {2, 1, 4, 3}));
    CHECK(equal(Solution().swapPairs(
            make_list(1, 2, 3, 4, 5)), {2, 1, 4, 3, 5}));
    CHECK(equal(Solution().swapPairs(
            make_list(1, 2, 3, 4, 5, 6)), {2, 1, 4, 3, 6, 5}));
}
