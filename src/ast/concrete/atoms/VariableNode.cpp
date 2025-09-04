#include "VariableNode.h"

VariableNode::VariableNode(const double value, const uint32_t label): label(label), _primal_value(value), _tangent_value(1) {}
VariableNode::~VariableNode() = default;

double VariableNode::primal_value() {
    return _primal_value;
}

double VariableNode::partial_derivative(uint32_t variable_label) {
    return label == variable_label ? _tangent_value : 0;
}

void VariableNode::accept(const AstVisitor *visitor) {
    // variables are ast leaves, no operation needed.
}

