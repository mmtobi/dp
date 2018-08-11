#ifndef Node_h
#define Node_h

#include <memory>

class Visitor;

class Node {
public:
    virtual ~Node() = 0;

    virtual int value() const;
    virtual std::shared_ptr<Node> left() const;
    virtual std::shared_ptr<Node> right() const;

    virtual void accept(Visitor&& visitor) const = 0;
};

class Leaf_Node : public Node {
public:
    Leaf_Node(int value);
    virtual ~Leaf_Node();

    virtual int value() const;

    virtual void accept(Visitor&& visitor) const;

private:
    int value_;    
};

class Binary_Node : public Node {
public:
    Binary_Node(std::shared_ptr<Node> left, std::shared_ptr<Node> right);
    virtual ~Binary_Node() = 0;

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

class Negate_Node : public Node {
public:
    Negate_Node(std::shared_ptr<Node> child);
    virtual ~Negate_Node();

    virtual int value() const;
    virtual std::shared_ptr<Node> left() const;

    virtual void accept(Visitor&& visitor) const;

private:
    std::shared_ptr<Node> child_;
    int value_;    
};

#endif
