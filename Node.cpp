//
// Created by marci on 3/26/2026.
//

#include "Node.h"

Node::Node(const int value, const int id) {
    this->value = value;
    this->id = id;
    left = nullptr;
    right = nullptr;
    priority = rand();
}