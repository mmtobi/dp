#include "Visitor.h"
#include <iostream>

void Print_Visitor::visit(const Leaf_Node& leaf_node) {
    std::cout << leaf_node.value() << " ";
}

void Print_Visitor::visit(const Add_Node& add_node) {
    std::cout << "+ ";
}

void Print_Visitor::visit(const Subtract_Node& subtract_node) {
    std::cout << "- ";
}

void Print_Visitor::visit(const Multiply_Node& multiply_node) {
    std::cout << "* ";
}

void Print_Visitor::visit(const Divide_Node& divide_node) {
    std::cout << "/ ";
}

void Print_Visitor::visit(const Negate_Node& negate_node) {
    std::cout << "- ";
}
