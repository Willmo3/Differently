#include "TangentVisitor.h"

#include <iostream>
#include <ostream>
#include <cmath>


/*
 * Constructors
 */
TangentVisitor::TangentVisitor() = default;
TangentVisitor::~TangentVisitor() = default;

/*
 * Visit functions
 */
void TangentVisitor::visit(BinaryOpNode *node) {
    // Compute partial derivatives wrt all variables.
    for (uint32_t variable_index = 0; variable_index < 3; variable_index++) {
        double computed_deriv = -1;

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
                computed_deriv = node->right->numeric_value() * node->left->partial_derivative(variable_index)
                                 + node->left->numeric_value() * node->right->partial_derivative(variable_index);
                break;
            }
            case BinaryOpNode::DIV: {
                computed_deriv = (node->right->numeric_value() * node->left->partial_derivative(variable_index)
                    - node->left->numeric_value() * node->right->partial_derivative(variable_index))
                    / std::pow(node->right->numeric_value(), 2);
                break;
            }
            // While exponentiation is a function and so subject to chain rule, it takes two arguments.
            case BinaryOpNode::EXP: {
                // Chain rule:
                // f'(g(x)) * g'(x)
                // Potential problem: complications when a is non-constant.
                auto g_prime = node->right->partial_derivative(variable_index);
                // ln(a) * a^x
                auto f_prime = log(node->right->numeric_value()) * node->numeric_value();
                computed_deriv = g_prime * f_prime;
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
void TangentVisitor::visit(UnaryOpNode *node) {
    for (uint32_t variable_index = 0; variable_index < 3; variable_index++) {
        double computed_deriv = -1;

        switch (node->optype()) {
            case UnaryOpNode::POW: {
                // TODO: need to know primal value of each variable in subexpr.

            }
            default: {
                std::cerr << "Not yet implemented" << std::endl;
                break;
            }
        }
    }
}
void TangentVisitor::visit(AstNode *node) {
    // This should be invoked whenever an arbitrary node, i.e. an atom node, is visited.
    // Since atom nodes have their values defined at construction time, this is a no-op.
}