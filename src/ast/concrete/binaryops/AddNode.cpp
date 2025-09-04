#include "AddNode.h"

// Values uninitialized until code run.
AddNode::AddNode(AstNode *left, AstNode *right): BinaryOpNode(left, right) {}
AddNode::~AddNode() = default;

// Additive expression: primal = left + right.
void AddNode::accept(const AstVisitor *visitor) {
    _primal_value = left()->primal_value() + right()->primal_value();

    compute_partial_derivatives([this](const uint32_t i) -> double
        {
            return left()->partial_derivative(i) + right()->partial_derivative(i);
        });
}