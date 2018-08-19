#ifndef Node_h
#define Node_h

#include <memory>

class Visitor;
class Node_Impl;
class Iterator;
enum class Traversal_Type;

enum class Node_Type {
    LEAF,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    NEGATE
};

class Node {
public:
    Node(std::shared_ptr<Node_Impl> node_impl);

    int value() const;
    std::shared_ptr<Node> left() const;
    std::shared_ptr<Node> right() const;

    void accept(Visitor& visitor);

    virtual Iterator begin(Traversal_Type traversal_type);
    virtual Iterator end(Traversal_Type traversal_type);

    virtual bool operator==(const Node& rhs) const;
    virtual bool operator!=(const Node& rhs) const;

private:
    std::shared_ptr<Node_Impl> node_impl_;
};

class Node_Impl {
public:
    virtual int value() const;
    virtual std::shared_ptr<Node> left() const;
    virtual std::shared_ptr<Node> right() const;

    virtual void accept(Visitor& visitor) = 0;
};

class Leaf_Node : public Node_Impl {
public:
    Leaf_Node(int value);

    virtual int value() const;

    virtual void accept(Visitor& visitor);

private:
    int value_;    
};

class Binary_Node : public Node_Impl {
public:
    Binary_Node(std::shared_ptr<Node> left, std::shared_ptr<Node> right);

    virtual std::shared_ptr<Node> left() const;
    virtual std::shared_ptr<Node> right() const;

protected:
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> right_;
};

class Add_Node : public Binary_Node {
public:
    using Binary_Node::Binary_Node;

    virtual int value() const;

    virtual void accept(Visitor& visitor);
};

class Subtract_Node : public Binary_Node {
public:
    using Binary_Node::Binary_Node;

    virtual int value() const;

    virtual void accept(Visitor& visitor);
};

class Multiply_Node : public Binary_Node {
public:
    using Binary_Node::Binary_Node;

    virtual int value() const;

    virtual void accept(Visitor& visitor);
};

class Divide_Node : public Binary_Node {
public:
    using Binary_Node::Binary_Node;

    virtual int value() const;

    virtual void accept(Visitor& visitor);
};

class Negate_Node : public Node_Impl {
public:
    Negate_Node(std::shared_ptr<Node> child);

    virtual int value() const;
    virtual std::shared_ptr<Node> left() const;

    virtual void accept(Visitor& visitor);

private:
    std::shared_ptr<Node> child_;
    int value_;    
};

#endif
