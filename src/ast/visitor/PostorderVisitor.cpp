#include "PostorderVisitor.h"

#include <iostream>
#include <ostream>
#include <cmath>

/*
 * Constructors
 */
PostorderVisitor::PostorderVisitor() = default;
PostorderVisitor::~PostorderVisitor() = default;

/*
 * Visit functions.
 */

void PostorderVisitor::visit(BinaryOpNode *node) {
    // Compute primal values wrt all vars.
    // TODO: split primal computation into separate pass.
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
        default: {
            std::cerr << "Not yet implemented" << std::endl;
            break;
        }
    }

    // Compute partial derivatives wrt all variables.
    // TODO: separate loop from selection to reduce nesting.
    for (uint32_t variable_index = 0; variable_index < 3; variable_index++) {
        double computed_deriv;

        switch (node->optype()) {
            case BinaryOpNode::ADD: {
                computed_deriv = node->left->partial_derivative(variable_index) + node->right->partial_derivative(variable_index);
                break;
            }
            case BinaryOpNode::SUB: {
                computed_deriv = node->left->partial_derivative(variable_index) - node->right->partial_derivative(variable_index);
                break;
            }
            case BinaryOpNode::MULT: {
                computed_deriv = node->right->primal_value() * node->left->partial_derivative(variable_index)
                                 + node->left->primal_value() * node->right->partial_derivative(variable_index);
                break;
            }
            case BinaryOpNode::DIV: {
                computed_deriv = (node->right->primal_value() * node->left->partial_derivative(variable_index)
                    - node->left->primal_value() * node->right->partial_derivative(variable_index))
                    / std::pow(node->right->primal_value(), 2);
                break;
            }
            default: {
                std::cerr << "Not yet implemented" << std::endl;
                break;
            }
        }

        node->_partial_derivatives[variable_index] = computed_deriv;
    }
}
void PostorderVisitor::visit(UnaryOpNode *node) {
    // TODO: not yet implemented -- no unary ops yet supported.
}
void PostorderVisitor::visit(AstNode *node) {
    // This should be invoked whenever an arbitrary node, i.e. an atom node, is visited.
    // Since atom nodes have their values defined at construction time, this is a no-op.
}