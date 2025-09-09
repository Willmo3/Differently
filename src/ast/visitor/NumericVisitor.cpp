//
// Created by will on 9/8/25.
//

#include "NumericVisitor.h"

#include <cmath>
#include <iostream>

#include "../unaryops/PowNode.h"
/*
 * Constructors
 */
NumericVisitor::NumericVisitor() = default;
NumericVisitor::~NumericVisitor() = default;

/*
 * Visit functions
 */
void NumericVisitor::visit(BinaryOpNode *node) {
    // Compute primal values wrt all variables.
    switch (node->optype()) {
        case BinaryOpNode::ADD: {
            node->_numeric_value = node->left->numeric_value() + node->right->numeric_value();
            break;
        }
        case BinaryOpNode::SUB: {
            node->_numeric_value = node->left->numeric_value() - node->right->numeric_value();
            break;
        }
        case BinaryOpNode::MULT: {
            node->_numeric_value = node->left->numeric_value() * node->right->numeric_value();
            break;
        }
        case BinaryOpNode::DIV: {
            node->_numeric_value = node->left->numeric_value() / node->right->numeric_value();
            break;
        }
        case BinaryOpNode::EXP: {
            node->_numeric_value = pow(node->left->numeric_value(), node->right->numeric_value());
            break;
        }
        default: {
            std::cerr << "Not yet implemented" << std::endl;
            break;
        }
    }

    // The total value is then the sum of these subvalues.
}

void NumericVisitor::visit(UnaryOpNode *node) {
    switch (node->optype()) {
        case UnaryOpNode::POW: {
            node->_numeric_value = pow(node->child->numeric_value(), dynamic_cast<PowNode *>(node)->exp_factor());
        }
        default: {
            std::cerr << "Not yet implemented" << std::endl;
            break;
        };
    }
}
void NumericVisitor::visit(AstNode *node) {
    // This should be invoked whenever an arbitrary node, i.e. an atom node, is visited.
    // Since atom nodes have their values defined at construction time, this is a no-op.
}