//
// Created by will on 9/4/25.
//

#include "DivNode.h"


/*
 * Constructors
 */
DivNode::DivNode(AstNode *left, AstNode *right): BinaryOpNode(left, right) {}
DivNode::~DivNode() = default;

BinaryOpNode::BinaryOpType DivNode::optype() {
    return DIV;
}