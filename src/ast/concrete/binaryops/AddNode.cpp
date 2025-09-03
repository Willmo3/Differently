#include "AddNode.h"

// Values uninitialized until code run.
AddNode::AddNode(AstNode *left, AstNode *right): BinaryOpNode(left, right) {}
AddNode::~AddNode() = default;

// Additive expression: primal = left + right.
void AddNode::accept(const AstVisitor *visitor) {
    _primal_value = left()->primal_value() + right()->primal_value();

    for (int i = 0; i < 3; i++) {
        this->_partial_derivatives[i] = left()->partial_derivative(i) + right()->partial_derivative(i);
    }
}