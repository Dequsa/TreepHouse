//
// Created by marci on 3/26/2026.
//

#include "Node.h"

Node::Node(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
    priority = rand();
}