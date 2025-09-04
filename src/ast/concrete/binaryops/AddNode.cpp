#include "AddNode.h"

/*
 * Constructors
 */
AddNode::AddNode(AstNode *left, AstNode *right): BinaryOpNode(left, right) {}
AddNode::~AddNode() = default;

BinaryOpNode::BinaryOpType AddNode::optype() {
    return ADD;
}