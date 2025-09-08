#include <iostream>
#include <ostream>

#include "src/ast/atoms/ConstantNode.h"
#include "src/ast/atoms/VariableNode.h"
#include "src/ast/visitor/TangentVisitor.h"
#include "src/ast/visitor/PrimalVisitor.h"

int main() {
    auto primal_visitor = PrimalVisitor();
    auto tangent_visitor = TangentVisitor();

    // auto number = ConstantNode(3.0);
    // auto variable = VariableNode(256, 0);
    // auto add_node = BinaryOpNode(BinaryOpNode::ADD, &number, &variable);
    //
    // add_node.accept(&primal_visitor);
    // add_node.accept(&tangent_visitor);
    // std::cout << add_node.partial_derivative(0) << std::endl;
    //
    // auto variable2 = VariableNode(2, 0);
    // auto variable3 = VariableNode(2, 0);
    // auto mult_node = BinaryOpNode(BinaryOpNode::MULT, &variable2, &variable3);
    //
    // mult_node.accept(&primal_visitor);
    // mult_node.accept(&tangent_visitor);
    // std::cout << mult_node.partial_derivative(0) << std::endl;

    auto x = VariableNode(2, 0);
    auto constant_factor = ConstantNode(2);
    auto x_mult = BinaryOpNode(BinaryOpNode::MULT, &constant_factor, &x);

    auto y = VariableNode(4, 1);
    auto y_mult = BinaryOpNode(BinaryOpNode::MULT, &constant_factor, &y);

    auto div = BinaryOpNode(BinaryOpNode::DIV, &x_mult, &y_mult);
    div.accept(&primal_visitor);
    div.accept(&tangent_visitor);
    std::cout << div.partial_derivative(0) << std::endl;

    // auto x = VariableNode(256, 0);
    // auto y = VariableNode(128, 1);
    // auto sub = BinaryOpNode(BinaryOpNode::SUB, &x, &y);
    //
    // visitor.visit(&sub);
    // std::cout << sub.primal_value() << std::endl;
    // std::cout << sub.partial_derivative(1) << std::endl;

    // TODO: if using pattern matching for binary operations, do we need types for all of them?
}
