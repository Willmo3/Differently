#include "ConstantNode.h"

#include <iostream>

ConstantNode::ConstantNode(const double value) : _primal_value(value), _tangent_value(0) {}

double ConstantNode::primal_value() { return _primal_value; }
double ConstantNode::tangent_value() { return _tangent_value; }

void ConstantNode::accept(const AstVisitor *visitor) {
    // Since numbers always have primals of n and derivatives of 0, nothing to do!
}
