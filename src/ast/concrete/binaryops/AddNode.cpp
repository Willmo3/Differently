#include "AddNode.h"

// Values uninitialized until code run.
AddNode::AddNode(AstNode *left, AstNode *right):BinaryOpNode(left, right), _primal_value(0), _tangent_value(0) {}
AddNode::~AddNode() = default;

double AddNode::primal_value() {
    return _primal_value;
}

double AddNode::tangent_value() {
    return _tangent_value;
}

// Additive expression: primal = left + right.
void AddNode::accept(const AstVisitor *visitor) {
    _primal_value = left()->primal_value() + right()->primal_value();
    _tangent_value = left()->tangent_value() + right()->tangent_value();
}