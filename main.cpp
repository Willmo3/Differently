#include <iostream>
#include <ostream>

#include "src/ast/concrete/atoms/ConstantNode.h"
#include "src/ast/concrete/atoms/VariableNode.h"
#include "src/ast/concrete/binaryops/AddNode.h"
#include "src/ast/concrete/binaryops/MultNode.h"
#include "src/ast/visitor/PostorderVisitor.h"

int main() {
    ConstantNode number = ConstantNode(3.0);
    VariableNode variable = VariableNode(256);
    AddNode add_node = AddNode(&number, &variable);

    PostorderVisitor visitor = PostorderVisitor();
    visitor.visit(&add_node);

    VariableNode variable2 = VariableNode(2);
    VariableNode variable3 = VariableNode(2);
    MultNode mult_node = MultNode(&variable2, &variable3);

    visitor.visit(&mult_node);

    std::cout << mult_node.tangent_value() << std::endl;
}
