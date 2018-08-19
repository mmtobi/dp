#ifndef Node_Factory_h
#define Node_Factory_h

#include "Node.h"
#include <memory>

class Node_Factory_Impl;

class Node_Factory {
public:
    Node_Factory(std::shared_ptr<Node_Factory_Impl> node_factory_impl);

    std::shared_ptr<Node> make_node(Node_Type node_type, int value);
    std::shared_ptr<Node> make_node(Node_Type node_type, std::shared_ptr<Node> left, std::shared_ptr<Node> right);
    std::shared_ptr<Node> make_node(Node_Type node_type, std::shared_ptr<Node> child);

private:
    std::shared_ptr<Node_Factory_Impl> node_factory_impl_;
};

class Node_Factory_Impl {
public:
    virtual std::shared_ptr<Node> make_node(Node_Type node_type, int value) = 0;
    virtual std::shared_ptr<Node> make_node(Node_Type node_type, std::shared_ptr<Node> left, std::shared_ptr<Node> right) = 0;
    virtual std::shared_ptr<Node> make_node(Node_Type node_type, std::shared_ptr<Node> child) = 0;
};

class Standard_Node_Factory : public Node_Factory_Impl {
public:
    virtual std::shared_ptr<Node> make_node(Node_Type node_type, int value);
    virtual std::shared_ptr<Node> make_node(Node_Type node_type, std::shared_ptr<Node> left, std::shared_ptr<Node> right);
    virtual std::shared_ptr<Node> make_node(Node_Type node_type, std::shared_ptr<Node> child);
};
#endif
