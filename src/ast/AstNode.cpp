//
// Created by will on 9/8/25.
//

#include "AstNode.h"

#include <cstring>

/*
 * Constructors
 */
AstNode::AstNode() {
    _primal_value = 0;
    memset(&_partial_derivatives, 0, sizeof(_partial_derivatives));
}
AstNode::~AstNode() = default;

/*
 * Accessors
 */
double AstNode::primal_value() {
    return _primal_value;
}
double AstNode::partial_derivative(uint32_t variable_index) {
    return this->_partial_derivatives[variable_index];
}