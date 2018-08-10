#ifndef Node_h
#define Node_h

class Visitor;

class Node {
public:
    virtual ~Node() = 0;
    virtual int value() const;
    virtual Node* left() const;
    virtual Node* right() const;
    virtual void accept(Visitor& visitor) const = 0;
};

class Leaf_Node : public Node {
public:
    virtual Leaf_Node();
    virtual int value() const;
    virtual void accept(Visitor& visitor) const;
};

class Binary_Node : public Node {
    virtual ~Binary_Node();
    Binary_Node(Node* left, Node* right);
    virtual Node* left() const;
    virtual Node* right() const;
    virtual void accept(Visitor& visitor) const;    
};

class Add_Node : public Binary_Node {
    using Binary_Node::Binary_Node;
}

class Subtract_Node : public Binary_Node {
    using Binary_Node::Binary_Node;
}

class Multiply_Node : public Binary_Node {
    using Binary_Node::Binary_Node;
}

class Divide_Node : public Binary_Node {
    using Binary_Node::Binary_Node;
}

#endif