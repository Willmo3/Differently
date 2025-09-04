#include <iostream>
#include <ostream>

#include "src/ast/concrete/atoms/ConstantNode.h"
#include "src/ast/concrete/atoms/VariableNode.h"
#include "src/ast/concrete/binaryops/AddNode.h"
#include "src/ast/concrete/binaryops/DivNode.h"
#include "src/ast/concrete/binaryops/MultNode.h"
#include "src/ast/visitor/PostorderVisitor.h"

int main() {
    auto visitor = PostorderVisitor();

    auto number = ConstantNode(3.0);
    auto variable = VariableNode(256, 0);
    auto add_node = AddNode(&number, &variable);

    visitor.visit(&add_node);
    std::cout << add_node.partial_derivative(0) << std::endl;

    auto variable2 = VariableNode(2, 0);
    auto variable3 = VariableNode(2, 0);
    auto mult_node = MultNode(&variable2, &variable3);

    visitor.visit(&mult_node);
    std::cout << mult_node.partial_derivative(0) << std::endl;

    auto x = VariableNode(2, 0);
    auto constant_factor = ConstantNode(2);
    auto x_mult = MultNode(&constant_factor, &x);
    // visitor.visit(&x_mult);
    // std::cout << x_mult.primal_value() << std::endl;

    auto y = VariableNode(4, 1);
    auto y_mult = MultNode(&constant_factor, &y);
    // visitor.visit(&y_mult);
    // std::cout << y_mult.primal_value() << std::endl;

    auto div = DivNode(&x_mult, &y_mult);
    div.accept(&visitor);
    std::cout << div.partial_derivative(0) << std::endl;
}
