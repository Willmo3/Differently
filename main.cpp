#include <iostream>
#include <ostream>

#include "src/ast/concrete/atoms/ConstantNode.h"
#include "src/ast/concrete/atoms/VariableNode.h"
#include "src/ast/concrete/binaryops/AddNode.h"
#include "src/ast/visitor/PostorderVisitor.h"

int main() {
    ConstantNode number = ConstantNode(3.0);
    VariableNode variable = VariableNode(256);
    AddNode add_node = AddNode(&number, &variable);

    PostorderVisitor visitor = PostorderVisitor();
    visitor.visit(&add_node);

    std::cout << add_node.primal_value() << std::endl;
    std::cout << add_node.tangent_value() << std::endl;
}
