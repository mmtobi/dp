#include "Iterator.h"
#include "Node.h"

#include <iostream>

Iterator::Iterator(Iterator_Impl* iterator_impl)
: iterator_impl_(iterator_impl) {}

Node Iterator::operator*() {
    return iterator_impl_->operator*();
}

void Iterator::operator++() {
    iterator_impl_->operator++();
}

bool Iterator::operator==(const Iterator& rhs) const {
    return iterator_impl_->operator==(*rhs.iterator_impl_);
}

bool Iterator::operator!=(const Iterator& rhs) const {
    return iterator_impl_->operator!=(*rhs.iterator_impl_);
}

bool Iterator_Impl::operator==(const Iterator_Impl& rhs) const {
//    return *current_ == *rhs.current_;
    return typeid(*this) == typeid(rhs);
}

bool Iterator_Impl::operator!=(const Iterator_Impl& rhs) const {
//    return *current_ != *rhs.current_;
    return typeid(*this) != typeid(rhs);
}

Preorder_Iterator::Preorder_Iterator(const Node& node) {
//    std::cout << "ctor " << this << " " << node.node_impl_ << std::endl;
    stack_.push(node);
}

Node Preorder_Iterator::operator*() const {
//    std::cout << "Preorder_Iterator*" << this << std::endl;
//    return *current_;
    if (!stack_.empty()) {
        return stack_.top();
    } else {
        return Node(nullptr);
    }
}

void Preorder_Iterator::operator++() {
//    std::cout << "Preorder_Iterator++ " << this <<  std::endl;
    if (!stack_.empty()) {
        Node current = stack_.top();
        stack_.pop();

        if (current.right() != nullptr) {
            stack_.push(current.right());
        }

        if (current.left() != nullptr) {
            stack_.push(current.left());
        }
    }
//    else {
//        current_ = new Node(nullptr);
//    }
}

bool Preorder_Iterator::operator==(const Iterator_Impl& rhs) const {
    return Iterator_Impl::operator==(rhs)
        && stack_.top() == dynamic_cast<const Preorder_Iterator&>(rhs).stack_.top();
}

bool Preorder_Iterator::operator!=(const Iterator_Impl& rhs) const {
    return Iterator_Impl::operator!=(rhs)
        || operator*() != dynamic_cast<const Preorder_Iterator&>(rhs).operator*();
}
