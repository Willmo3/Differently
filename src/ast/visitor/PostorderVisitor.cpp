#include "PostorderVisitor.h"

#include "../abstract/UnaryOpNode.h"

PostorderVisitor::PostorderVisitor() = default;
PostorderVisitor::~PostorderVisitor() = default;


void PostorderVisitor::visit(AtomNode *node) {
    node->accept(this);
}

void PostorderVisitor::visit(BinaryOpNode *node) {
    // Postorder traversal: visit children first.
    visit(node->left());
    visit(node->right());

    node->accept(this);
}

void PostorderVisitor::visit(UnaryOpNode *node) {
    visit(node->child());

    node->accept(this);
}

void PostorderVisitor::visit(AstNode *node) {}
