//
// Created by will on 9/3/25.
//

#include "MultNode.h"

MultNode::MultNode(AstNode *left, AstNode *right): BinaryOpNode(left, right), _primal_value(0), _tangent_value(0) {}
MultNode::~MultNode() = default;

double MultNode::primal_value() {
    return _primal_value;
}
double MultNode::tangent_value() {
    return _tangent_value;
}

void MultNode::accept(const AstVisitor *visitor) {
    _primal_value = left()->primal_value() + right()->primal_value();

    // gf' + fg'
    _tangent_value =
        right()->primal_value() * left()->tangent_value()
        + left()->primal_value() * right()->tangent_value();
}
