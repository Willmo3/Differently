#include "PostorderVisitor.h"
#include "../abstract/UnaryOpNode.h"

/*
 * Constructors
 */
PostorderVisitor::PostorderVisitor() = default;
PostorderVisitor::~PostorderVisitor() = default;

void PostorderVisitor::visit(BinaryOpNode *node) {
    // Postorder traversal: visit children first.
    visit(node->left());
    visit(node->right());

    node->evaluate();
}
void PostorderVisitor::visit(UnaryOpNode *node) {
    visit(node->child());

    node->evaluate();
}
// Any other node must have no children, and so we simply evaluate.
void PostorderVisitor::visit(AstNode *node) {
    node->evaluate();
}
