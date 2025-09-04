#include "ConstantNode.h"

#include <iostream>

/*
 * Constructors
 */
ConstantNode::ConstantNode(const double value) : _primal_value(value), _tangent_value(0) {}
ConstantNode::~ConstantNode() = default;

/*
 * Accessors
 */
double ConstantNode::primal_value() { return _primal_value; }
double ConstantNode::partial_derivative(uint32_t index) { return 0; }
