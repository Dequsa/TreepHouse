//
// Created by marci on 3/26/2026.
//

#ifndef TREAPHOUSE_TREE_H
#define TREAPHOUSE_TREE_H
#include <unordered_set>

#include "Node.h"


class Tree {
private:
    std::unordered_set<int> existing_ids = {};
    std::unordered_map<int, Node*> id_to_node = {};
    void FreeTree(const Node *branch);
    Node *RotateLeft(Node *old_parent);
    Node *RotateRight(Node *old_parent);
public:
    Node *root = nullptr;

    Tree() = default;

    void PrintAllNodes(Node* branch);
    Node *InsertNode(Node *root, const int value, const int id);
    Node *DeleteNode(Node *branch, const int id);
    Node *FindNodeById(Node *branch, const int id);

    int GetNodeCount() const {return static_cast<int>(existing_ids.size()); }

    ~Tree() { FreeTree(this->root); };
};


#endif //TREAPHOUSE_TREE_H
