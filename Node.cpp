#include "Node.h"
#include "Visitor.h"
#include "Iterator.h"

Node::Node(Node_Impl* node_impl)
: node_impl_(node_impl) {}

int Node::value() const {
    return node_impl_->value();
}

Node_Impl* Node::left() const {
    return node_impl_->left();
}

Node_Impl* Node::right() const {
    return node_impl_->right();
}

Iterator Node::begin(Traversal_Type traversal_type) {
    return Iterator(new Preorder_Iterator(*this));
}

Iterator Node::end(Traversal_Type traversal_type) {
    return Iterator(new Preorder_Iterator(Node(nullptr)));
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

Node_Impl::~Node_Impl() {}

int Node_Impl::value() const { }

Node_Impl* Node_Impl::left() const {
    return nullptr;
}

Node_Impl* Node_Impl::right() const { 
    return nullptr;
}

Leaf_Node::Leaf_Node(int value) 
: value_(value) { }

Leaf_Node::~Leaf_Node() {}

int Leaf_Node::value() const {
    return value_;
}

void Leaf_Node::accept(Visitor& visitor) {
    visitor.visit(*this);
}

Binary_Node::Binary_Node(Node_Impl* left, Node_Impl* right)
: left_(left)
, right_(right) { }

Binary_Node::~Binary_Node() {}

Node_Impl* Binary_Node::left() const {
    return left_;
}

Node_Impl* Binary_Node::right() const {
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

Negate_Node::Negate_Node(Node_Impl* child)
: child_(child) { } 

Negate_Node::~Negate_Node() {}

int Negate_Node::value() const {
    return -value_;
}

void Negate_Node::accept(Visitor& visitor) {
    visitor.visit(*this);
}

Node_Impl* Negate_Node::left() const {
    return child_;
}

void Sentinel_Node::accept(Visitor& visitor) {
    visitor.visit(*this);
}
