#include <iostream>
#include <memory>

struct Node {
    int number = 0;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
};

void print_tree(const Node* root) {
    if (root == nullptr) {
        return;
    }
    print_tree(root->left.get());
    std::cout << root->number << ' ';
    print_tree(root->right.get());
}

void insert_node(std::unique_ptr<Node>& root, int number) {
    if (root == nullptr) {
        root = std::make_unique<Node>();
        root->number = number;
    } else if (number < root->number) {
        insert_node(root->left, number);
    } else {
        insert_node(root->right, number);
    }
}

int main() {
    /* add nodes to the tree on loop
     * std::unique_ptr<Node> tree;
    for (int i = 1; i <= 7; ++i) {
        insert_node(tree, i);
    }
    */

    // tree of size 0
    auto tree = std::make_unique<Node>();

    auto n = std::make_unique<Node>();
    n->number = 2;
    tree = std::move(n);

    n = std::make_unique<Node>();
    n->number = 1;
    tree->left = std::move(n);

    n = std::make_unique<Node>();
    n->number = 3;
    tree->right = std::move(n);

    // tree is correctly built
    std::cout << "Tree in-order traversal: ";
    print_tree(tree.get());

    return 0;
}