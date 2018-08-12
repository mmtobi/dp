#ifndef Visitor_h
#define Visitor_h

#include "Node.h"

class Visitor {
public:
    virtual void visit(const Leaf_Node& leaf_node) = 0;
    virtual void visit(const Add_Node& add_node) = 0;
    virtual void visit(const Subtract_Node& subtract_node) = 0;
    virtual void visit(const Multiply_Node& multiply_node) = 0;
    virtual void visit(const Divide_Node& divide_node) = 0;
    virtual void visit(const Negate_Node& negate_node) = 0;
    virtual void visit(const Sentinel_Node& sentinel_node) = 0;
};

class Print_Visitor : public Visitor {
public:
    virtual void visit(const Leaf_Node& leaf_node);
    virtual void visit(const Add_Node& add_node);
    virtual void visit(const Subtract_Node& subtract_node);
    virtual void visit(const Multiply_Node& multiply_node);
    virtual void visit(const Divide_Node& divide_node);
    virtual void visit(const Negate_Node& negate_node);
    virtual void visit(const Sentinel_Node& sentinel_node);
};

#endif
