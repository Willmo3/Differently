#include "UnaryOpNode.h"

#include "../visitor/AstVisitor.h"

/*
 * Constructors
 */
UnaryOpNode::UnaryOpNode(AstNode *child): child(child) {}
UnaryOpNode::~UnaryOpNode() = default;

/*
 * Traversal
 */
void UnaryOpNode::accept(AstVisitor *visitor) {
    child->accept(visitor);
    visitor->visit(this);
}
