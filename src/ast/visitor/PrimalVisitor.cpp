//
// Created by will on 9/9/25.
//

#include "PrimalVisitor.h"

#include <cmath>
#include <iostream>

#include "../unaryops/PowNode.h"
/*
 * Constructors
 */
PrimalVisitor::PrimalVisitor() = default;
PrimalVisitor::~PrimalVisitor() = default;

/*
 * Visit functions
 */
void PrimalVisitor::visit(BinaryOpNode *node) {
    // Compute partial primal values wrt all variables.
    for (uint32_t variable_index = 0; variable_index < 3; variable_index++) {
        double computed_primal = -1;

        switch (node->optype()) {
            case BinaryOpNode::ADD: {
                computed_primal = node->left->partial_primal(variable_index) + node->right->partial_primal(variable_index);
                break;
            }
            case BinaryOpNode::SUB: {
                computed_primal = node->left->partial_primal(variable_index) - node->right->partial_primal(variable_index);
                break;
            }
            case BinaryOpNode::MULT: {
                computed_primal = node->left->partial_primal(variable_index) * node->right->partial_primal(variable_index);
                break;
            }
            case BinaryOpNode::DIV: {
                if (node->right->partial_primal(variable_index) == 0) {
                    computed_primal = 0;
                } else {
                    computed_primal = node->left->partial_primal(variable_index) / node->right->partial_primal(variable_index);
                }
                break;
            }
            default: {
                std::cerr << "Not yet implemented" << std::endl;
                break;
            }
        }

        node->_primal_values[variable_index] = computed_primal;
    }
}
void PrimalVisitor::visit(UnaryOpNode *node) {
    for (uint32_t variable_index = 0; variable_index < 3; variable_index++) {
        double computed_primal = -1;

        switch (node->optype()) {
            // For exponentiation, if the subvalue includes any terms from the corresponding var, the entire expression is preserved.
            case UnaryOpNode::POW: {
                if (node->child->partial_primal(variable_index) == 0) {
                    computed_primal = 0;
                } else {
                    computed_primal = pow(node->child->numeric_value(), dynamic_cast<PowNode *>(node)->exp_factor());
                }
                break;
            }
            case UnaryOpNode::EXP: {
                if (node->child->partial_primal(variable_index) == 0) {
                    computed_primal = 0;
                } else {
                    computed_primal = exp(node->child->numeric_value());
                }
                break;
            }
            case UnaryOpNode::TANH: {
                if (node->child->partial_primal(variable_index) == 0) {
                    computed_primal = 0;
                } else {
                    computed_primal = tanh(node->child->numeric_value());
                }
                break;
            }
            default: {
                std::cerr << "Not yet implemented" << std::endl;
                break;
            }
        }

        node->_primal_values[variable_index] = computed_primal;
    }
}
void PrimalVisitor::visit(AstNode *node) {
    // This should be invoked whenever an arbitrary node, i.e. an atom node, is visited.
    // Since atom nodes have their values defined at construction time, this is a no-op.
}