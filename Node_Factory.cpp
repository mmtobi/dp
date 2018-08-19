#include "Node_Factory.h"

Node_Factory::Node_Factory(std::shared_ptr<Node_Factory_Impl> node_factory_impl)
: node_factory_impl_(node_factory_impl) {}

std::shared_ptr<Node> Node_Factory::make_node(Node_Type node_type, int value) {
    return node_factory_impl_->make_node(node_type, value);
}

std::shared_ptr<Node> Node_Factory::make_node(Node_Type node_type, std::shared_ptr<Node> left, std::shared_ptr<Node> right) {
    return node_factory_impl_->make_node(node_type, left, right);
}
std::shared_ptr<Node> Node_Factory::make_node(Node_Type node_type, std::shared_ptr<Node> child) {
    return node_factory_impl_->make_node(node_type, child);
}

std::shared_ptr<Node> Standard_Node_Factory::make_node(Node_Type node_type, int value) {
    switch (node_type) {
    case Node_Type::LEAF:
        return std::make_shared<Node>(std::make_shared<Leaf_Node>(value));
    default:
        return nullptr;
    }
}

std::shared_ptr<Node> Standard_Node_Factory::make_node(Node_Type node_type, std::shared_ptr<Node> left, std::shared_ptr<Node> right) {
    switch (node_type) {
    case Node_Type::ADD:
        return std::make_shared<Node>(std::make_shared<Add_Node>(left, right));
    case Node_Type::SUBTRACT:
        return std::make_shared<Node>(std::make_shared<Subtract_Node>(left, right));
    case Node_Type::MULTIPLY:
        return std::make_shared<Node>(std::make_shared<Multiply_Node>(left, right));
    case Node_Type::DIVIDE:
        return std::make_shared<Node>(std::make_shared<Divide_Node>(left, right));
    default:
        return nullptr;
    }
}

std::shared_ptr<Node> Standard_Node_Factory::make_node(Node_Type node_type, std::shared_ptr<Node> child) {
    switch (node_type) {
    case Node_Type::NEGATE:
        return std::make_shared<Node>(std::make_shared<Negate_Node>(child));
    default:
        return nullptr;
    }
}
