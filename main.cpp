#include "main.h"
#include "Node.h"
#include "Tree.h"
#include <iostream>
#include "InputHandler.h"

int main() {
    std::srand(time(nullptr));
    InputHandler handler;
    handler.GetUserInput();
    return 0;
}
