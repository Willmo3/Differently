#include "PostorderVisitor.h"

#include <iostream>
#include <stdexcept>

#include "../abstract/UnaryOpNode.h"

/*
 * Constructors
 */
PostorderVisitor::PostorderVisitor() = default;
PostorderVisitor::~PostorderVisitor() = default;

void PostorderVisitor::visit(AtomNode *node) {
    node->evaluate();
}
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
// Function defined for typechecking, but should never be invoked.
void PostorderVisitor::visit(AstNode *node) {
}
