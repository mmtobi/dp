#include "Node.h"
#include "Visitor.h"
#include "Iterator.h"
#include <memory>

int main() {
    // TODO: remove this hardcoding by using Factory
    Node expr(std::make_shared<Multiply_Node>(
            std::make_shared<Negate_Node>(std::make_shared<Leaf_Node>(5)),
            std::make_shared<Add_Node>(
                std::make_shared<Leaf_Node>(4), 
                std::make_shared<Leaf_Node>(3))));

    Print_Visitor print_visitor;

    for (Iterator itr = expr.begin(Traversal_Type::PREORDER); 
        itr != expr.end(Traversal_Type::PREORDER);
        ++itr)
    {
        (*itr).accept(print_visitor);
    }
}
