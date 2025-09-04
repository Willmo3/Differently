//
// Created by will on 9/3/25.
//

#include "MultNode.h"

/*
 * Constructors
 */
MultNode::MultNode(AstNode *left, AstNode *right): BinaryOpNode(left, right) {}
MultNode::~MultNode() = default;

BinaryOpNode::BinaryOpType MultNode::optype() {
    return MULT;
}