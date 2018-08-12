#ifndef Node_h
#define Node_h

class Visitor;
class Node_Impl;
class Iterator;
class Iterator_Impl;
enum class Traversal_Type;

class Node {
public:
    Node(Node_Impl* node_impl);

    int value() const;
    Node_Impl* left() const;
    Node_Impl* right() const;

    void accept(Visitor& visitor);

    virtual Iterator begin(Traversal_Type traversal_type);
    virtual Iterator end(Traversal_Type traversal_type);

    virtual bool operator==(const Node& rhs) const;
    virtual bool operator!=(const Node& rhs) const;

private:
    Node_Impl* node_impl_;
};

class Node_Impl {
public:
    virtual ~Node_Impl() = 0;

    virtual int value() const;
    virtual Node_Impl* left() const;
    virtual Node_Impl* right() const;

    virtual void accept(Visitor& visitor) = 0;
};

class Leaf_Node : public Node_Impl {
public:
    Leaf_Node(int value);
    virtual ~Leaf_Node();

    virtual int value() const;

    virtual void accept(Visitor& visitor);

private:
    int value_;    
};

class Binary_Node : public Node_Impl {
public:
    Binary_Node(Node_Impl* left, Node_Impl* right);
    virtual ~Binary_Node() = 0;

    virtual Node_Impl* left() const;
    virtual Node_Impl* right() const;

protected:
    Node_Impl* left_;
    Node_Impl* right_;
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
    Negate_Node(Node_Impl* child);
    virtual ~Negate_Node();

    virtual int value() const;
    virtual Node_Impl* left() const;

    virtual void accept(Visitor& visitor);

private:
    Node_Impl* child_;
    int value_;    
};

#endif
