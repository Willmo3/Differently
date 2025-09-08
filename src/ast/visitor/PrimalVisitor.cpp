//
// Created by will on 9/8/25.
//

#include "PrimalVisitor.h"

#include <cmath>
#include <iostream>
/*
 * Constructors
 */
PrimalVisitor::PrimalVisitor() = default;
PrimalVisitor::~PrimalVisitor() = default;

/*
 * Visit functions
 */

void PrimalVisitor::visit(BinaryOpNode *node) {
    switch (node->optype()) {
        case BinaryOpNode::ADD: {
            node->_primal_value = node->left->primal_value() + node->right->primal_value();
            break;
        }
        case BinaryOpNode::SUB: {
            node->_primal_value = node->left->primal_value() - node->right->primal_value();
            break;
        }
        case BinaryOpNode::MULT: {
            node->_primal_value = node->left->primal_value() * node->right->primal_value();
            break;
        }
        case BinaryOpNode::DIV: {
            node->_primal_value = node->left->primal_value() / node->right->primal_value();
            break;
        }
        case BinaryOpNode::EXP: {
            node->_primal_value = pow(node->left->primal_value(), node->right->primal_value());
            break;
        }
        default: {
            std::cerr << "Not yet implemented" << std::endl;
            break;
        }
    }
}

void PrimalVisitor::visit(UnaryOpNode *node) {
    // TODO: not yet implemented -- no unary ops yet supported
}
void PrimalVisitor::visit(AstNode *node) {
    // This should be invoked whenever an arbitrary node, i.e. an atom node, is visited.
    // Since atom nodes have their values defined at construction time, this is a no-op.
}