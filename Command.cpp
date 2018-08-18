#include "Command.h"
#include "Visitor.h"

Command::Command(std::shared_ptr<Command_Impl> command_impl)
: command_impl_(command_impl) {}

void Command::execute() {
    command_impl_->execute();
}

Print_Command::Print_Command(
    std::shared_ptr<Node> expression, 
    Traversal_Type traversal_type)
: expression_(expression)
, traversal_type_(traversal_type) {}

void Print_Command::execute() {
    Print_Visitor print_visitor;

    for (Iterator itr = expression_->begin(traversal_type_); 
        itr != expression_->end(traversal_type_);
        ++itr)
    {
        (*itr).accept(print_visitor);
    }
}
