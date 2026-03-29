//
// Created by marci on 3/26/2026.
//

#ifndef TREAPHOUSE_NODE_H
#define TREAPHOUSE_NODE_H
#pragma once
#include <memory>

class Node {
    int id{};
    int value{};
    int priority{};

public:
    Node *left{};
    Node *right{};
    int sub_tree_size {};
    int sum {};
    int min_id {};
    int max_id {};

    Node(const int value, const int id);
    void UpdateSum();
    ~Node() = default;

    // setters
    void SetPrice(const int price) { this->value = price; }

    // getters
    int GetValue() const { return value; }
    int GetId() const { return id; }
    int GetPriority() const { return priority; }
    int GetSum() const { return sum; }
    int GetSubTreeSize() const { return sub_tree_size; }
};


#endif //TREAPHOUSE_NODE_H
