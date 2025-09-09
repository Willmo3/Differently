//
// Created by will on 9/9/25.
//

#include "PowNode.h"

/*
 * Constructors
 */
PowNode::PowNode(AstNode *child, double exp_factor): UnaryOpNode(child, POW), _exp_factor(exp_factor) {}
PowNode::~PowNode() = default;

/*
 * Accessors
 */
double PowNode::exp_factor() const {
    return _exp_factor;
}
