#include "Node.h"
#include "Visitor.h"
#include "Iterator.h"
#include <iostream>

int main() {
    // TODO: remove this hardcoding by using Factory
    Node expr(new Multiply_Node(
            new Negate_Node(new Leaf_Node(5)),
            new Add_Node(
                new Leaf_Node(4),
                new Leaf_Node(3))));

    Print_Visitor print_visitor;

    for (Iterator itr = expr.begin(Traversal_Type::PREORDER); 
        itr != expr.end(Traversal_Type::PREORDER);
        ++itr)
    {
        (*itr).accept(print_visitor);
    }
}
