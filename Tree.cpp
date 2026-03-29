//
// Created by marci on 3/26/2026.
//

#include "Tree.h"
#include <iostream>

void Tree::FreeTree(const Node *branch) {
    if (branch == nullptr) {
        return;
    }
    FreeTree(branch->left);
    FreeTree(branch->right);
    delete branch;
}

void Tree::PrintAllNodes(Node *branch) {
    if (branch == nullptr) {
        return;
    }

    // go max left
    PrintAllNodes(branch->left);

    std::cout << "ID: " << branch->GetId() << " | Price: " << branch->GetValue() << std::endl;

    // go right
    PrintAllNodes(branch->right);
}

Node *Tree::InsertNode(Node *root, const int value, const int id) {
    if (root == nullptr) {
        if (existing_ids.contains(id)) {
            Node *existing_node = id_to_node[id];
            if (existing_node) {
                existing_node->SetPrice(value);
            }
            return root;
        }
        existing_ids.insert(id);
        Node *temp = new Node(value, id);
        id_to_node[id] = temp;
        return temp;
    }

    if (id > root->GetId()) {
        root->right = InsertNode(root->right, value, id);

        // if right child has higher priority rotate left
        if (root->right != nullptr && root->right->GetPriority() > root->GetPriority()) {
            root = RotateLeft(root);
        }
    } else {
        root->left = InsertNode(root->left, value, id);

        // if left child has higher priority rotate right
        if (root->left != nullptr && root->left->GetPriority() > root->GetPriority()) {
            root = RotateRight(root);
        }
    }

    return root;
}

Node *Tree::DeleteNode(Node *branch, const int id) {
    if (branch == nullptr) {
        return nullptr;
    }

    // if not found children must search
    if (branch->GetId() != id) {
        branch->left = DeleteNode(branch->left, id);
        branch->right = DeleteNode(branch->right, id);
        return branch;
    }

    // case no children
    if (!(branch->left && branch->right)) {
        delete branch;
        return nullptr;
    }

    // case one child
    if (!branch->right) {
        Node *temp = branch->left;
        delete branch;
        return temp;
    }
    if (!branch->left) {
        Node *temp = branch->right;
        delete branch;
        return temp;
    }

    // case two children
    if (branch->left->GetPriority() > branch->right->GetPriority()) {
        branch = RotateRight(branch);
        branch->right = DeleteNode(branch->right, id);
    } else {
        branch = RotateLeft(branch);
        branch->left = DeleteNode(branch->left, id);
    }

    return branch;
}

Node *Tree::FindNodeById(Node *branch, const int id) {
    // if nothing found return nullptr up
    if (branch == nullptr) {
        return nullptr;
    }

    // if match return the pointer up
    if (branch->GetId() == id) {
        return branch;
    }

    // look for the id on the left child
    if (Node *left_side = FindNodeById(branch->left, id); left_side != nullptr) {
        return left_side;
    }

    // look at the right child for the id
    return FindNodeById(branch->right, id);
}

Node *Tree::RotateLeft(Node *old_parent) {
    Node *new_parent = old_parent->right;
    Node *inner_subtree = new_parent->left;

    new_parent->left = old_parent;
    old_parent->right = inner_subtree;

    return new_parent;
}

Node *Tree::RotateRight(Node *old_parent) {
    Node *new_parent = old_parent->left;
    Node *inner_subtree = new_parent->right;

    new_parent->right = old_parent;
    old_parent->left = inner_subtree;

    return new_parent;
}