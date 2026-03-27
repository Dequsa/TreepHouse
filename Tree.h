//
// Created by marci on 3/26/2026.
//

#ifndef TREAPHOUSE_TREE_H
#define TREAPHOUSE_TREE_H
#include "Node.h"


class Tree {
private:
    void FreeTree(const Node *branch);

    Node *RotateLeft(Node *y);

    Node *RotateRight(Node *x);

public:
    Node *root = nullptr;

    Tree() = default;

    Node *InsertNode(Node *root, const int value);
    Node *FindNodeByValue(const int value);
    Node *FindNodeById(const int id);
    ~Tree() { FreeTree(this->root); };
};


#endif //TREAPHOUSE_TREE_H
