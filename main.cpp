#include <iostream>
#include <ostream>

#include "src/ast/atoms/ConstantNode.h"
#include "src/ast/atoms/VariableNode.h"
#include "src/ast/unaryops/PowNode.h"
#include "src/ast/visitor/TangentVisitor.h"
#include "src/ast/visitor/PrimalVisitor.h"
#include "src/ast/visitor/NumericVisitor.h"

void test_add() {
    auto numeric_visitor = NumericVisitor();
    auto primal_visitor = PrimalVisitor();
    auto tangent_visitor = TangentVisitor();

    auto number = ConstantNode(3.0);
    auto variable = VariableNode(256, 0);
    auto add_node = BinaryOpNode(BinaryOpNode::ADD, &number, &variable);

    add_node.accept(&numeric_visitor);
    add_node.accept(&primal_visitor);
    add_node.accept(&tangent_visitor);
    std::cout << add_node.numeric_value() << std::endl;
    std::cout << add_node.partial_primal(0) << std::endl;
    std::cout << add_node.partial_primal(1) << std::endl;
    std::cout << add_node.partial_derivative(0) << std::endl;
}

void test_multiply() {
    auto numeric_visitor = NumericVisitor();
    auto primal_visitor = PrimalVisitor();
    auto tangent_visitor = TangentVisitor();

    auto x = VariableNode(2, 0);
    auto constant_factor = ConstantNode(2);
    auto x_mult = BinaryOpNode(BinaryOpNode::MULT, &constant_factor, &x);

    auto y = VariableNode(4, 1);
    auto y_mult = BinaryOpNode(BinaryOpNode::MULT, &constant_factor, &y);

    auto div = BinaryOpNode(BinaryOpNode::DIV, &x_mult, &y_mult);
    div.accept(&numeric_visitor);
    div.accept(&primal_visitor);
    div.accept(&tangent_visitor);
    std::cout << div.partial_derivative(0) << std::endl;
}

void test_pow() {
    auto numeric_visitor = NumericVisitor();
    auto primal_visitor = PrimalVisitor();
    auto tangent_visitor = TangentVisitor();

    auto x = VariableNode(2, 0);
    auto y = VariableNode(3, 0);
    auto add = BinaryOpNode(BinaryOpNode::ADD, &x, &y);
    auto pow = PowNode(&add, 3);

    pow.accept(&numeric_visitor);
    pow.accept(&primal_visitor);
    pow.accept(&tangent_visitor);

    std::cout << pow.numeric_value() << std::endl;
    std::cout << pow.partial_primal(0) << std::endl;
    std::cout << pow.partial_primal(1) << std::endl;
    std::cout << pow.partial_derivative(0) << std::endl;
    std::cout << pow.partial_derivative(1) << std::endl;
}

void test_root() {
    auto numeric_visitor = NumericVisitor();
    auto primal_visitor = PrimalVisitor();
    auto tangent_visitor = TangentVisitor();

    auto x = VariableNode(2, 0);
    auto y = VariableNode(2, 0);
    auto add = BinaryOpNode(BinaryOpNode::ADD, &x, &y);
    auto pow = PowNode(&add, 0.5);

    pow.accept(&numeric_visitor);
    pow.accept(&primal_visitor);
    pow.accept(&tangent_visitor);

    std::cout << pow.numeric_value() << std::endl;
    std::cout << pow.partial_primal(0) << std::endl;
    std::cout << pow.partial_primal(1) << std::endl;
    std::cout << pow.partial_derivative(0) << std::endl;
    std::cout << pow.partial_derivative(1) << std::endl;
}

void test_exp() {
    auto numeric_visitor = NumericVisitor();
    auto primal_visitor = PrimalVisitor();
    auto tangent_visitor = TangentVisitor();

    auto x = VariableNode(2, 0);
    auto exp = UnaryOpNode(&x, UnaryOpNode::EXP);

    exp.accept(&numeric_visitor);
    exp.accept(&primal_visitor);
    exp.accept(&tangent_visitor);

    std::cout << exp.numeric_value() << std::endl;
    std::cout << exp.partial_primal(0) << std::endl;
    std::cout << exp.partial_primal(1) << std::endl;
    std::cout << exp.partial_derivative(0) << std::endl;
    std::cout << exp.partial_derivative(1) << std::endl;
}

int main() {
    test_exp();
    return 0;
}
