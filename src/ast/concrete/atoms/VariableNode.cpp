#include "VariableNode.h"

/*
 * Constructors
 */
VariableNode::VariableNode(const double value, const uint32_t label): label(label) {
    _primal_value = value;
    // Tangent value for this var when differentiated wrt = 1.
    _partial_derivatives[label] = 1;
}
VariableNode::~VariableNode() = default;

/*
 * Accessors
 */
double VariableNode::primal_value() {
    return _primal_value;
}
/**
 * @param variable_label label of variable to get partial derivative wrt.
 * @return the tangent value of this variable (i.e. 1) if differentiating wrt this var, otherwise 0.
 */
double VariableNode::partial_derivative(uint32_t variable_label) {
    return _partial_derivatives[variable_label];
}