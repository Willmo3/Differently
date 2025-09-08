#include "UnaryOpNode.h"

#include "../visitor/AstVisitor.h"

/*
 * Constructors
 */
UnaryOpNode::UnaryOpNode(AstNode *child): child(child), _primal_value(0) {}
UnaryOpNode::~UnaryOpNode() = default;

/*
 * Accessors
 */
double UnaryOpNode::primal_value() {
    return _primal_value;
}
double UnaryOpNode::partial_derivative(uint32_t variable_label) {
    return this->_partial_derivatives[variable_label];
}

/*
 * Traversers
 */
void UnaryOpNode::accept(AstVisitor *visitor) {
    child->accept(visitor);
    visitor->visit(this);
}
