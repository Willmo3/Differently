#include "UnaryOpNode.h"

#include "../visitor/AstVisitor.h"

/*
 * Constructors
 */
UnaryOpNode::UnaryOpNode(AstNode *child, UnaryOpType type): child(child), _optype(type) {}
UnaryOpNode::~UnaryOpNode() = default;

/*
 * Accessors
 */
UnaryOpNode::UnaryOpType UnaryOpNode::optype() const { return _optype; }

/*
 * Traversal
 */
void UnaryOpNode::accept(AstVisitor *visitor) {
    child->accept(visitor);
    visitor->visit(this);
}
