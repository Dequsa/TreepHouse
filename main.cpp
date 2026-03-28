#include "main.h"
#include "Node.h"
#include "Tree.h"
#include <iostream>

// Node *InsertNode(Node *root, const int value, const int id) {
//     if (root == nullptr) {
//         return new Node(value, id);
//     }
//
//     if (value > root->GetValue()) {
//         root->left = InsertNode(root->left, value, id);
//     }
//     else {
//         root->right = InsertNode(root->right, value, id);
//     }
//
//     return root;
// }



int main() {
    auto tree = Tree();
    tree.root = tree.InsertNode(tree.root, 1, 1);
    tree.root = tree.InsertNode(tree.root, 2, 2);
    tree.PrintAllNodes(tree.root);
    tree.root = tree.InsertNode(tree.root, 3, 1);
    std::cout << std::endl;
    tree.PrintAllNodes(tree.root);
    return 0;
}
