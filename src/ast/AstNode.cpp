//
// Created by will on 9/8/25.
//

#include "AstNode.h"

#include <cstring>

/*
 * Constructors
 */
AstNode::AstNode(): _numeric_value(0) {
    memset(&_primal_values, 0, sizeof(_primal_values));
    memset(&_partial_derivatives, 0, sizeof(_partial_derivatives));
}
AstNode::~AstNode() = default;

/*
 * Accessors
 */
double AstNode::numeric_value() {
    return _numeric_value;
}
double AstNode::partial_primal(uint32_t variable_label) {
    return _primal_values[variable_label];
}
double AstNode::partial_derivative(uint32_t variable_index) {
    return _partial_derivatives[variable_index];
}