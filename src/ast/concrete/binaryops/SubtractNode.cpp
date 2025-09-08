//
// Created by will on 9/8/25.
//

#include "SubtractNode.h"

/*
 * Constructors
 */
SubtractNode::SubtractNode(AstNode *left, AstNode *right): BinaryOpNode(left, right) {}
SubtractNode::~SubtractNode() = default;

BinaryOpNode::BinaryOpType SubtractNode::optype() {
    return SUB;
}
