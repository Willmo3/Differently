//
// Created by will on 9/3/25.
//

#include "MultNode.h"

MultNode::MultNode(AstNode *left, AstNode *right): BinaryOpNode(left, right) {}
MultNode::~MultNode() = default;

void MultNode::accept(const AstVisitor *visitor) {
    _primal_value = left()->primal_value() + right()->primal_value();

    for (int i = 0; i < 3; i++) {
        //gf' + fg'
        this->_partial_derivatives[i] = right()->primal_value() * left()->partial_derivative(i)
            + left()->primal_value() * right()->partial_derivative(i);
    }
}
