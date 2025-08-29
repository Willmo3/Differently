#include <iostream>
#include <ostream>

#include "src/ast/concrete/atoms/ConstantNode.h"
#include "src/ast/concrete/atoms/VariableNode.h"
#include "src/ast/visitor/PostorderVisitor.h"

int main() {
    ConstantNode number = ConstantNode(3.0);
    VariableNode variable = VariableNode(256);

    PostorderVisitor visitor = PostorderVisitor();
    visitor.visit(&number);
    visitor.visit(&variable);

    std::cout << variable.primal_value() << std::endl;
    std::cout << variable.tangent_value() << std::endl;
}
