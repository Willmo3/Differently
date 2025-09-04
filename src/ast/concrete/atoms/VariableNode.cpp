#include "VariableNode.h"

/*
 * Constructors
 */
VariableNode::VariableNode(const double value, const uint32_t label): label(label), _primal_value(value), _tangent_value(1) {}
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
    return label == variable_label ? _tangent_value : 0;
}

/*
 * Evaluators -- since variables are ast leaves, no operation is needed.
 */
void VariableNode::evaluate() {}