#include "Node.h"
#include "Visitor.h"

Node::Node(std::unique_ptr<Node_Impl> node_impl)
: node_impl_(std::move(node_impl)) {}

int Node::value() const {
    return node_impl_->value();
}

std::shared_ptr<Node_Impl> Node::left() const {
    return node_impl_->left();
}

std::shared_ptr<Node_Impl> Node::right() const {
    return node_impl_->right();
}

void Node::accept(Visitor&& visitor) const {
    node_impl_->accept(std::move(visitor));
}

Node_Impl::~Node_Impl() {}

int Node_Impl::value() const { }

std::shared_ptr<Node_Impl> Node_Impl::left() const {
    return nullptr;
}

std::shared_ptr<Node_Impl> Node_Impl::right() const { 
    return nullptr;
}

Leaf_Node::Leaf_Node(int value) 
: value_(value) { }

Leaf_Node::~Leaf_Node() {}

int Leaf_Node::value() const {
    return value_;
}

void Leaf_Node::accept(Visitor&& visitor) const {
    visitor.visit(*this);
}

Binary_Node::Binary_Node(std::shared_ptr<Node_Impl> left, std::shared_ptr<Node_Impl> right)
: left_(left)
, right_(right) { }

Binary_Node::~Binary_Node() {}

std::shared_ptr<Node_Impl> Binary_Node::left() const {
    return left_;
}

std::shared_ptr<Node_Impl> Binary_Node::right() const {
    return right_;
}

int Add_Node::value() const {
    return left_->value() + right_->value();
}

void Add_Node::accept(Visitor&& visitor) const {
    visitor.visit(*this);
}

int Subtract_Node::value() const {
    return left_->value() - right_->value();
}

void Subtract_Node::accept(Visitor&& visitor) const {
    visitor.visit(*this);
}

int Multiply_Node::value() const {
    return left_->value() * right_->value();
}

void Multiply_Node::accept(Visitor&& visitor) const {
    visitor.visit(*this);
}

int Divide_Node::value() const {
    return left_->value() / right_->value();
}

void Divide_Node::accept(Visitor&& visitor) const {
    visitor.visit(*this);
}

Negate_Node::Negate_Node(std::shared_ptr<Node_Impl> child)
: child_(child) { } 

Negate_Node::~Negate_Node() {}

int Negate_Node::value() const {
    return -value_;
}

void Negate_Node::accept(Visitor&& visitor) const {
    visitor.visit(*this);
}

std::shared_ptr<Node_Impl> Negate_Node::left() const {
    return child_;
}
