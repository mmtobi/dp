#ifndef Node_h
#define Node_h

class Node {
public:
    virtual ~Node() = 0;
    virtual int value() const;
    virtual Node* left() const;
    virtual Node* right() const;
//    virtual void accept(Visitor& visitor) const;
};

#endif