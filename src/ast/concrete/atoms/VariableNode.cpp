#include "VariableNode.h"

VariableNode::VariableNode(double value): _primal_value(value), _tangent_value(1) {}
VariableNode::~VariableNode() = default;

double VariableNode::primal_value() {
    return _primal_value;
}

double VariableNode::tangent_value() {
    return _tangent_value;
}

void VariableNode::accept(const AstVisitor *visitor) {
    // variables are ast leaves, no operation needed.
}

