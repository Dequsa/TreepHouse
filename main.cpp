#include "main.h"
#include "Node.h"
#include "Tree.h"
#include <memory>

Node *InsertNode(Node *root, const int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value > root->GetValue()) {
        root->left = InsertNode(root->left, value);
    }
    else {
        root->right = InsertNode(root->right, value);
    }

    return root;
}



int main() {
    auto tree = Tree();
    tree.InsertNode(tree.root, 5);
    return 0;
}
