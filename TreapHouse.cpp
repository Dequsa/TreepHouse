#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// ==========================================
// Node
// ==========================================
class Node {
    long long id{};
    long long value{};
    int priority{};

public:
    Node *left{};
    Node *right{};
    int sub_tree_size {};
    long long sum {};
    long long min_id {};
    long long max_id {};

    Node(const long long value, const long long id);
    void UpdateSum();
    ~Node() = default;

    // setters
    void SetPrice(const long long price) { this->value = price; }

    // getters
    long long GetValue() const { return value; }
    long long GetId() const { return id; }
    int GetPriority() const { return priority; }
    long long GetSum() const { return sum; }
    int GetSubTreeSize() const { return sub_tree_size; }
};

// ==========================================
// Tree
// ==========================================
class Tree {
private:
    void FreeTree(Node *branch);
    Node *RotateLeft(Node *old_parent);
    Node *RotateRight(Node *old_parent);
public:
    Node *root = nullptr;

    Tree() = default;

    // void PrintAllNodes(Node* branch);
    Node *InsertNode(Node *root, const long long value, const long long id);
    Node *DeleteNode(Node *branch, const long long id);
    long long SumBetweenIds(Node *branch, long long id_min, long long id_max);

    int GetNodeCount() const { return root ? root->sub_tree_size : 0; }

    ~Tree() { FreeTree(this->root); };
};

// ==========================================
// InputHandler
// ==========================================
class InputHandler {
private:
    Tree my_tree={};

    void ChooseAndExecuteOperation(const char operation);
public:
    InputHandler() { my_tree.root = nullptr;};
    ~InputHandler() = default;

    void GetUserInput();
};

// ==========================================
// Node
// ==========================================
Node::Node(const long long value, const long long id) {
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

// ==========================================
// Tree
// ==========================================
void Tree::FreeTree(Node *branch) {
    if (branch == nullptr) {
        return;
    }
    FreeTree(branch->left);
    FreeTree(branch->right);
    delete branch;
}

// void Tree::PrintAllNodes(Node *branch) {
//     if (branch == nullptr) {
//         return;
//     }

//     // go max left
//     PrintAllNodes(branch->left);

//     std::cout << "ID: " << branch->GetId() << " | Price: " << branch->GetValue() << std::endl;

//     // go right
//     PrintAllNodes(branch->right);
// }

Node *Tree::InsertNode(Node *root, const long long value, const long long id) {
    if (root == nullptr) {
        return new Node(value, id);
    }

    if (root->GetId() == id) {
        root->SetPrice(value);
        root->UpdateSum();
        return root;
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

    if (root) { root->UpdateSum(); }

    return root;
}

Node *Tree::DeleteNode(Node *branch, const long long id) {
    if (branch == nullptr) {
        return nullptr;
    }

    // if not found children must search
    if (branch->GetId() != id) {
        if (id > branch->GetId()) {
            branch->right = DeleteNode(branch->right, id);
        } else {
            branch->left = DeleteNode(branch->left, id);
        }
        branch->UpdateSum();
        return branch;
    }

    // case no children
    if (!branch->left && !branch->right) {
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

    if (branch) { branch->UpdateSum(); }
    return branch;
}

long long Tree::SumBetweenIds(Node *branch, long long id_min, long long id_max) {
    if (!branch) {
        return 0;
    }
    if (id_min > id_max) {
        return 0;
    }

    if (branch->min_id > id_max || branch->max_id < id_min) {
        return 0;
    }

    if (branch->min_id >= id_min && branch->max_id <= id_max) {
        return branch->sum;
    }

    long long ans = 0;
    // FIXED: Checking the node's specific ID, not the subtree's max_id
    if (branch->GetId() >= id_min && branch->GetId() <= id_max) {
        ans += branch->GetValue();
    }
    ans += SumBetweenIds(branch->left, id_min, id_max);
    ans += SumBetweenIds(branch->right, id_min, id_max);
    return ans;
}

Node *Tree::RotateLeft(Node *old_parent) {
    Node *new_parent = old_parent->right;
    Node *inner_subtree = new_parent->left;

    new_parent->left = old_parent;
    old_parent->right = inner_subtree;

    old_parent->UpdateSum();
    new_parent->UpdateSum();

    return new_parent;
}

Node *Tree::RotateRight(Node *old_parent) {
    Node *new_parent = old_parent->left;
    Node *inner_subtree = new_parent->right;

    new_parent->right = old_parent;
    old_parent->left = inner_subtree;

    old_parent->UpdateSum();
    new_parent->UpdateSum();

    return new_parent;
}

// ==========================================
// InputHandler
// ==========================================
void InputHandler::ChooseAndExecuteOperation(const char operation) {
    using std::cin;
    using std::cout;

    switch (operation) {
        case 'A': {
            long long id, price;
            cin >> id >> price;
            my_tree.root = my_tree.InsertNode(my_tree.root, price, id);
            break;
        }
        case 'C': {
            cout << my_tree.GetNodeCount() << '\n';
            break;
        }
        case 'D': {
            long long id;
            cin >> id;
            my_tree.root = my_tree.DeleteNode(my_tree.root, id);
            break;
        }
        case 'S': {
            long long min_id, max_id;
            cin >> min_id >> max_id;
            const long long sum = my_tree.SumBetweenIds(my_tree.root, min_id, max_id);
            cout << sum << '\n';
            break;
        }
    }
}

void InputHandler::GetUserInput() {
    using std::cin;

    int num_of_operations = 0;
    while (!num_of_operations) {
        cin >> num_of_operations;
    }
    if (num_of_operations == -1) {
        return;
    }

    while (num_of_operations--) {
        char operation;
        cin >> operation;
        ChooseAndExecuteOperation(operation);
    }
}

// ==========================================
// Main
// ==========================================
int main() {
    std::srand(time(nullptr));
    InputHandler handler;
    handler.GetUserInput();
    return 0;
}