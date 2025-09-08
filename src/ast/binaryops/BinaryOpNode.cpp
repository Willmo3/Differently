#include "BinaryOpNode.h"

#include "../AstNode.h"
#include "../visitor/AstVisitor.h"

/*
 * Constructors
 */
BinaryOpNode::BinaryOpNode(BinaryOpType type, AstNode *left, AstNode *right): _type(type), left(left), right(right) {}
BinaryOpNode::~BinaryOpNode() = default;

/*
 * Accessors
 */
BinaryOpNode::BinaryOpType BinaryOpNode::optype() const {
    return _type;
}

/*
 * Traversal
 */
void BinaryOpNode::accept(AstVisitor *visitor) {
    left->accept(visitor);
    right->accept(visitor);
    visitor->visit(this);
}