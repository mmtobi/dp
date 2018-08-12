#include "Node.h"
#include "Visitor.h"
#include "Iterator.h"

Node::Node(std::shared_ptr<Node_Impl> node_impl)
: node_impl_(node_impl) {}

int Node::value() const {
    return node_impl_->value();
}

std::shared_ptr<Node_Impl> Node::left() const {
    return node_impl_->left();
}

std::shared_ptr<Node_Impl> Node::right() const {
    return node_impl_->right();
}

Iterator Node::begin(Traversal_Type traversal_type) {
    return Iterator(std::make_shared<Preorder_Iterator>(*this));
}

Iterator Node::end(Traversal_Type traversal_type) {
    return Iterator(std::make_shared<Preorder_Iterator>(Node(nullptr)));
}

void Node::accept(Visitor& visitor) {
    node_impl_->accept(visitor);
}

bool Node::operator==(const Node& rhs) const {
    return node_impl_ == rhs.node_impl_;
}

bool Node::operator!=(const Node& rhs) const {
    return node_impl_ != rhs.node_impl_;
}

int Node_Impl::value() const { }

std::shared_ptr<Node_Impl> Node_Impl::left() const {
    return nullptr;
}

std::shared_ptr<Node_Impl> Node_Impl::right() const { 
    return nullptr;
}

Leaf_Node::Leaf_Node(int value) 
: value_(value) { }

int Leaf_Node::value() const {
    return value_;
}

void Leaf_Node::accept(Visitor& visitor) {
    visitor.visit(*this);
}

Binary_Node::Binary_Node(std::shared_ptr<Node_Impl> left, std::shared_ptr<Node_Impl> right)
: left_(left)
, right_(right) { }

std::shared_ptr<Node_Impl> Binary_Node::left() const {
    return left_;
}

std::shared_ptr<Node_Impl> Binary_Node::right() const {
    return right_;
}

int Add_Node::value() const {
    return left_->value() + right_->value();
}

void Add_Node::accept(Visitor& visitor) {
    visitor.visit(*this);
}

int Subtract_Node::value() const {
    return left_->value() - right_->value();
}

void Subtract_Node::accept(Visitor& visitor) {
    visitor.visit(*this);
}

int Multiply_Node::value() const {
    return left_->value() * right_->value();
}

void Multiply_Node::accept(Visitor& visitor) {
    visitor.visit(*this);
}

int Divide_Node::value() const {
    return left_->value() / right_->value();
}

void Divide_Node::accept(Visitor& visitor) {
    visitor.visit(*this);
}

Negate_Node::Negate_Node(std::shared_ptr<Node_Impl> child)
: child_(child) { } 

int Negate_Node::value() const {
    return -value_;
}

void Negate_Node::accept(Visitor& visitor) {
    visitor.visit(*this);
}

std::shared_ptr<Node_Impl> Negate_Node::left() const {
    return child_;
}
