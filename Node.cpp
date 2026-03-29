//
// Created by marci on 3/26/2026.
//

#include "Node.h"

#include <algorithm>

Node::Node(const int value, const int id) {
    this->value = value;
    this->id = id;
    left = nullptr;
    right = nullptr;
    priority = rand();
    UpdateSum();
}

void Node::UpdateSum() {
    sub_tree_size = 1;
    min_id = id;
    max_id = id;
    sum = value;

    if (left) {
        sum += left->sum;
        min_id = std::min(min_id, left->min_id);
        max_id = std::max(max_id, left->max_id);
        sub_tree_size += left->sub_tree_size;
    }
    if (right) {
        sum += right->sum;
        min_id = std::min(min_id, right->min_id);
        max_id = std::max(max_id, right->max_id);
        sub_tree_size += right->sub_tree_size;
    }
}
