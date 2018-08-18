#include "Node.h"
#include "Iterator.h"
#include "Command.h"
#include <memory>

int main() {
    // TODO: remove this hardcoding by using Factory
    Node expr(
            std::make_shared<Multiply_Node>(
                std::make_shared<Negate_Node>(std::make_shared<Leaf_Node>(5)),
                std::make_shared<Add_Node>(
                    std::make_shared<Leaf_Node>(4), 
                    std::make_shared<Leaf_Node>(3))));

    Command print_command(
                std::make_shared<Print_Command>(
                    std::make_shared<Node>(expr), 
                    Traversal_Type::PREORDER));
    print_command.execute();
}
