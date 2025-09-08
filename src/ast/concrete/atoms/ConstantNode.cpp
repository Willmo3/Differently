#include "ConstantNode.h"

#include <iostream>

/*
 * Constructors
 */
ConstantNode::ConstantNode(const double value) {
    _primal_value = value;
}
ConstantNode::~ConstantNode() = default;
