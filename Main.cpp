#include "Node.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "Hello World" << std::endl;
    
    // TODO: remove this hardcoding by using Factory
    std::shared_ptr<Node> expr 
        = std::make_shared<Multiply_Node>(
            std::make_shared<Negate_Node>(std::make_shared<Leaf_Node>(5)),
            std::make_shared<Add_Node>(
                std::make_shared<Leaf_Node>(4),
                std::make_shared<Leaf_Node>(3)));
}
