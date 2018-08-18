#ifndef Command_h
#define Command_h

#include "Iterator.h"
#include "Node.h"
#include <memory>

class Command_Impl;

class Command {
public:
    Command(std::shared_ptr<Command_Impl> command_impl);
    void execute();
private:
    std::shared_ptr<Command_Impl> command_impl_;
};

class Command_Impl {
public:    
    virtual void execute() = 0;
};

class Print_Command : public Command_Impl {
public:
    Print_Command(std::shared_ptr<Node> expression, Traversal_Type traversal_type);
    virtual void execute();

private:
    std::shared_ptr<Node> expression_;
    Traversal_Type traversal_type_;
};
#endif
