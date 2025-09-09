#include "VariableNode.h"

/*
 * Constructors
 */
VariableNode::VariableNode(const double value, const uint32_t label): label(label) {
    _numeric_value = value;
    _primal_values[label] = value;
    // Tangent value for this var when differentiated wrt = 1.
    _partial_derivatives[label] = 1;
}
VariableNode::~VariableNode() = default;