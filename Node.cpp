#include "Node.h"

Node::~Node() {}

int Node::value() const { }

std::shared_ptr<Node> Node::left() const {
    return nullptr;
}

std::shared_ptr<Node> Node::right() const { 
    return nullptr;
}

Leaf_Node::Leaf_Node(int value) 
: value_(value) { }

Leaf_Node::~Leaf_Node() {}

int Leaf_Node::value() const {
    return value_;
}

Binary_Node::Binary_Node(std::shared_ptr<Node> left, std::shared_ptr<Node> right)
: left_(left)
, right_(right) { }

Binary_Node::~Binary_Node() {}

std::shared_ptr<Node> Binary_Node::left() const {
    return left_;
}

std::shared_ptr<Node> Binary_Node::right() const {
    return right_;
}

int Add_Node::value() const {
    return left_->value() + right_->value();
}

int Subtract_Node::value() const {
    return left_->value() - right_->value();
}

int Multiply_Node::value() const {
    return left_->value() * right_->value();
}

int Divide_Node::value() const {
    return left_->value() / right_->value();
}

Negate_Node::Negate_Node(std::shared_ptr<Node> child)
: child_(child) { } 

Negate_Node::~Negate_Node() {}

int Negate_Node::value() const {
    return -value_;
}

std::shared_ptr<Node> Negate_Node::left() const {
    return child_;
}
