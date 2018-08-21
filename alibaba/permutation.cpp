#include <deque>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

namespace {

struct n_tree_node {
    n_tree_node(int v) : val(v) { }

    void print_path() {
        std::cout << "[ ";
        for (auto v : path)
            std::cout << v << " ";
        std::cout << "]" << std::endl;
    }

    int val;
    std::vector<std::unique_ptr<n_tree_node>> children;
    std::unordered_set<int> path_unique_ele;
    std::vector<int> path;
};

void print_permutation(const int n) {
    n_tree_node root(0);
    std::deque<n_tree_node*> queue(1, &root);
    for (int level = 0; level < n; ++level) {
        int cur_queue_len = queue.size();
        for (int i = 0; i < cur_queue_len; ++i) {
            for (int j = 1; j <= n; ++j) {
                auto parent = queue[0];
                if (parent->path_unique_ele.count(j) == 0) {
                    auto child = new n_tree_node(j);
                    child->path_unique_ele = parent->path_unique_ele;
                    child->path_unique_ele.emplace(j);
                    child->path = parent->path;
                    child->path.push_back(j);
                    queue.push_back(child);
                    parent->children.emplace_back(child);
                }
            }
            queue.pop_front();
        }
    }

    std::vector<std::vector<int>> permutations;

    auto node = &root;
    std::vector<n_tree_node*> stack(1, node);
    int cnt = 0;
    while (not stack.empty()) {
        auto node = stack.back();
        stack.pop_back();
        if (node->children.empty()) {
            node->print_path();
            ++cnt;
        }
        for (int i = node->children.size() - 1; i >= 0; --i)
            stack.push_back(node->children[i].get());
    }
    std::cout << "total: " << cnt << std::endl;
}

}

int main() {
    print_permutation(1);  /* test case 1 */
    print_permutation(2);  /* test case 2 */
    print_permutation(3);  /* test case 3 */
    print_permutation(4);  /* test case 4 */
    return 0;
}
