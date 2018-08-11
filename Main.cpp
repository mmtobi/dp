#include "Node.h"
#include "Visitor.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "Hello World" << std::endl;
    
    // TODO: remove this hardcoding by using Factory
    Node expr(std::make_unique<Multiply_Node>(
            std::make_shared<Negate_Node>(std::make_shared<Leaf_Node>(5)),
            std::make_shared<Add_Node>(
                std::make_shared<Leaf_Node>(4),
                std::make_shared<Leaf_Node>(3))));

    expr.accept(Print_Visitor());
}
