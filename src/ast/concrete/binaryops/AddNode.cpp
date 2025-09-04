#include "AddNode.h"

/*
 * Constructors
 */
AddNode::AddNode(AstNode *left, AstNode *right): BinaryOpNode(left, right) {}
AddNode::~AddNode() = default;

/*
 * Evaluator.
 * Partial derivative atom: f' + g'
 */
void AddNode::evaluate() {
    _primal_value = left()->primal_value() + right()->primal_value();

    compute_partial_derivatives([this](const uint32_t i) -> double
        {
            return left()->partial_derivative(i) + right()->partial_derivative(i);
        });
}