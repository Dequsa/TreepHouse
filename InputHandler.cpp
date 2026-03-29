//
// Created by Kacper Marciniak on 3/28/26.
//

#include "InputHandler.h"
#include <iostream>

void InputHandler::ChooseAndExecuteOperation(const char operation) {
    using std::cin;
    using std::cout;

    switch (operation) {
        case 'A':
            int id, price;
            cin >> id >> price;
            my_tree.root = my_tree.InsertNode(my_tree.root, price, id);
            break;
        case 'C':
            cout << '\n' << my_tree.GetNodeCount();
            break;
        case 'D':
            cin >> id;
            my_tree.root = my_tree.DeleteNode(my_tree.root, id);
            break;
        case 'S':
            long long min_id, max_id;
            cin >> min_id >> max_id;
            const long long sum = my_tree.SumBetweenIds(my_tree.root, min_id, max_id);
            cout << sum << '\n';
            break;
    }
}

void InputHandler::GetUserInput() {
    using std::cout;
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
    // my_tree.PrintAllNodes(my_tree.root);
}
