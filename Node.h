#ifndef Node_h
#define Node_h

#include <memory>

class Visitor;
class Node_Impl;


class Node {
public:
    Node(std::unique_ptr<Node_Impl> node_impl);

    int value() const;
    std::shared_ptr<Node_Impl> left() const;
    std::shared_ptr<Node_Impl> right() const;

    void accept(Visitor&& visitor) const;

private:
    std::unique_ptr<Node_Impl> node_impl_;
};

class Node_Impl {
public:
    virtual ~Node_Impl() = 0;

    virtual int value() const;
    virtual std::shared_ptr<Node_Impl> left() const;
    virtual std::shared_ptr<Node_Impl> right() const;

    virtual void accept(Visitor&& visitor) const = 0;
};

class Leaf_Node : public Node_Impl {
public:
    Leaf_Node(int value);
    virtual ~Leaf_Node();

    virtual int value() const;

    virtual void accept(Visitor&& visitor) const;

private:
    int value_;    
};

class Binary_Node : public Node_Impl {
public:
    Binary_Node(std::shared_ptr<Node_Impl> left, std::shared_ptr<Node_Impl> right);
    virtual ~Binary_Node() = 0;

    virtual std::shared_ptr<Node_Impl> left() const;
    virtual std::shared_ptr<Node_Impl> right() const;

protected:
    std::shared_ptr<Node_Impl> left_;
    std::shared_ptr<Node_Impl> right_;
};

class Add_Node : public Binary_Node {
public:
    using Binary_Node::Binary_Node;

    virtual int value() const;

    virtual void accept(Visitor&& visitor) const;
};

class Subtract_Node : public Binary_Node {
public:
    using Binary_Node::Binary_Node;

    virtual int value() const;

    virtual void accept(Visitor&& visitor) const;
};

class Multiply_Node : public Binary_Node {
public:
    using Binary_Node::Binary_Node;

    virtual int value() const;

    virtual void accept(Visitor&& visitor) const;
};

class Divide_Node : public Binary_Node {
public:
    using Binary_Node::Binary_Node;

    virtual int value() const;

    virtual void accept(Visitor&& visitor) const;
};

class Negate_Node : public Node_Impl {
public:
    Negate_Node(std::shared_ptr<Node_Impl> child);
    virtual ~Negate_Node();

    virtual int value() const;
    virtual std::shared_ptr<Node_Impl> left() const;

    virtual void accept(Visitor&& visitor) const;

private:
    std::shared_ptr<Node_Impl> child_;
    int value_;    
};

#endif
