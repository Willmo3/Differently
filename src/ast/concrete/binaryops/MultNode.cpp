//
// Created by will on 9/3/25.
//

#include "MultNode.h"

MultNode::MultNode(AstNode *left, AstNode *right): BinaryOpNode(left, right) {}
MultNode::~MultNode() = default;

void MultNode::accept(const AstVisitor *visitor) {
    _primal_value = left()->primal_value() + right()->primal_value();

    compute_partial_derivatives([this](const uint32_t i) -> double
        {
            return right()->primal_value() * left()->partial_derivative(i)
                + left()->primal_value() * right()->partial_derivative(i);
        });
}
