#include "Iterator.h"
#include "Command.h"
#include "Node_Factory.h"
#include <memory>

int main() {
    Node_Factory node_factory(std::make_shared<Standard_Node_Factory>());
    auto expr = node_factory.make_node(Node_Type::MULTIPLY,
            node_factory.make_node(Node_Type::NEGATE,
                node_factory.make_node(Node_Type::LEAF, 5)),
            node_factory.make_node(Node_Type::ADD,
                node_factory.make_node(Node_Type::LEAF, 4),
                node_factory.make_node(Node_Type::LEAF, 3)));

    Command print_command(std::make_shared<Print_Command>(expr, Traversal_Type::PREORDER));
    print_command.execute();
}
