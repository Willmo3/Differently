#include "BinaryOpNode.h"

#include <cstring>
#include <functional>

#include "AstNode.h"
#include "../visitor/AstVisitor.h"

/*
 * Constructors
 */
BinaryOpNode::BinaryOpNode(AstNode *left, AstNode *right): left(left), right(right), _primal_value(0) {
    // TODO: generalize to vector
    memset(&_partial_derivatives, 0, sizeof(_partial_derivatives));
}
BinaryOpNode::~BinaryOpNode() = default;

/*
 * Accessors
 */
double BinaryOpNode::primal_value() {
    return _primal_value;
}
double BinaryOpNode::partial_derivative(uint32_t variable_index) {
    return this->_partial_derivatives[variable_index];
}

/*
 * Computational functions
 */
void BinaryOpNode::accept(AstVisitor *visitor) {
    left->accept(visitor);
    right->accept(visitor);
    visitor->visit(this);
}