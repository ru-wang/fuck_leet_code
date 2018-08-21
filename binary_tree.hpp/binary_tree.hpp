#pragma once

#include <iostream>
#include <vector>

struct tree_node {
    tree_node(int v) : val(v) { }

    static tree_node* construct_bitree(const std::vector<int>& arr) {
        auto root = new tree_node(arr[0]);
        for (int i = 1; i < arr.size(); ++i) {
        }
        return root;
    }

    static void insert(tree_node*& p, int val) {
        if (p == nullptr) {
            p = new tree_node(val);
            return;
        }
        if (val <= p->val) return insert(p->l, val);
        else               return insert(p->r, val);
    }

    static void bfs(tree_node* root);

    static void dfs_postorder_recur(tree_node* root);
    static void dfs_inorder_recur(tree_node* root);
    static void dfs_preorder_recur(tree_node* root);

    static void dfs_postorder_nonrecur(tree_node* root);
    static void dfs_inorder_nonrecur(tree_node* root);
    static void dfs_preorder_nonrecur(tree_node* root);

    tree_node* l = nullptr;
    tree_node* r = nullptr;
    int val = 0;
};

inline void tree_node::dfs_preorder_nonrecur(tree_node* root) {
    if (root == nullptr) return;
    std::vector<tree_node*> stack;
    tree_node* node = root;
    stack.push_back(node);
    while (not stack.empty()) {
        auto node = stack.back();
        stack.pop_back();
        std::cout << node->val << " ";
        if (node->r) stack.push_back(node->r);
        if (node->l) stack.push_back(node->l);
    }
    std::cout << std::endl;
}

inline void tree_node::dfs_inorder_nonrecur(tree_node* root) {
    if (root == nullptr) return;
    std::vector<tree_node*> stack;
    tree_node* node = root;
    while (not stack.empty() || node) {
        if (node) {
            stack.push_back(node);
            node = node->l;
        } else {
            std::cout << stack.back()->val << " ";
            node = stack.back()->r;
            stack.pop_back();
        }
    }
    std::cout << std::endl;
}

inline void tree_node::dfs_postorder_nonrecur(tree_node* root) {
    if (root == nullptr) return;
    std::vector<tree_node*> stack;
    tree_node* node = root;
    tree_node* last_visited = nullptr;
    while (not stack.empty() || node) {
        if (node) {
            stack.push_back(node);
            node = node->l;
        } else {
            auto top = stack.back();
            if (top->r && top->r != last_visited) {
                node = top->r;
            } else {
                std::cout << top->val << " ";
                last_visited = top;
                stack.pop_back();
            }
        }
    }
    std::cout << std::endl;
}
