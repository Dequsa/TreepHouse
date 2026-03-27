//
// Created by marci on 3/26/2026.
//

#ifndef TREAPHOUSE_NODE_H
#define TREAPHOUSE_NODE_H
#pragma once
#include <memory>

class Node
{
private:
    int id{};
    int value{};
    int priority{};
public:
    Node* left{};
    Node* right{};

    Node(int value);
    ~Node() = default;
    int GetValue() const { return value;}
    int GetId() const { return id;}
    int GetPriority() const { return priority;}
};


#endif //TREAPHOUSE_NODE_H