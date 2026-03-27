//
// Created by marci on 3/26/2026.
//

#include "Tree.h"

void Tree::FreeTree(const Node *branch) {
    if (branch == nullptr) {
        return;
    }
    FreeTree(branch->left);
    FreeTree(branch->right);
    delete branch;
}

Node *Tree::InsertNode(Node *root, const int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->GetValue()) {
        root->right = InsertNode(root->right, value);

        // if left child has higher priority rotate right
        if (root->left->GetPriority() > root->GetPriority()) {
            root = RotateRight(root);
        }
    } else {
        root->left = InsertNode(root->left, value);

        // if right child has higher priority rotate left
        if (root->left->GetPriority() < root->GetPriority()) {
            root = RotateLeft(root);
        }
    }

    return root;
}

Node * Tree::FindNodeByValue(const int value) {
    return nullptr;
}

Node * Tree::FindNodeById(const int id) {
    return nullptr;
}

Node* Tree::RotateLeft(Node *y) {
    // copy y - parent x - right child
    Node *x = y->right;
    Node *T2 = x->right;

    // assign new parent do the swap
    x->right = y;
    y->left = T2;

    return x;
}

Node* Tree::RotateRight(Node *x) {
    // copy x - parent y - left child
    Node *y = x->left;
    Node *T2 = y->left;

    // assign new parent do the swap
    x->left = x;
    y->right = T2;

    return x;
}
