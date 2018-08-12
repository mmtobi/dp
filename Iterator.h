#ifndef Iterator_h
#define Iterator_h

#include <memory>
#include <stack>

enum class Traversal_Type {
    PREORDER
};

class Node;
class Iterator_Impl;

class Iterator {
public:
    Iterator(Iterator_Impl* iterator_impl);

    Node operator*();
    void operator++(); 
    bool operator==(const Iterator& rhs) const;
    bool operator!=(const Iterator& rhs) const;

private:
    Iterator_Impl* iterator_impl_;
};

class Iterator_Impl {
public:
    virtual Node operator*() const = 0;
    virtual void operator++() = 0;
    virtual bool operator==(const Iterator_Impl& rhs) const;
    virtual bool operator!=(const Iterator_Impl& rhs) const;

protected:
//    Node* current_;
};

class Preorder_Iterator : public Iterator_Impl {
public:
    Preorder_Iterator(const Node& node);

    virtual Node operator*() const;
    virtual void operator++();

    virtual bool operator==(const Iterator_Impl& rhs) const;
    virtual bool operator!=(const Iterator_Impl& rhs) const;

private:
    std::stack<Node> stack_;
};

#endif
