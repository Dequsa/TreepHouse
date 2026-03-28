//
// Created by Kacper Marciniak on 3/28/26.
//

#ifndef TREAPHOUSE_INPUTHANDLER_H
#define TREAPHOUSE_INPUTHANDLER_H
#include "Tree.h"


class InputHandler {
private:
    Tree my_tree={};

    void ChooseAndExecuteOperation(const char operation);
public:
    InputHandler() { my_tree.root = nullptr;};
    ~InputHandler() = default;

    void GetUserInput();
};


#endif //TREAPHOUSE_INPUTHANDLER_H