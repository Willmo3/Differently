#include "BinaryOpNode.h"

#include "AstNode.h"

BinaryOpNode::BinaryOpNode(AstNode *left, AstNode *right): left_(left), right_(right) {}

BinaryOpNode::~BinaryOpNode() = default;

AstNode *BinaryOpNode::left() const { return left_; }
AstNode *BinaryOpNode::right() const { return right_; }
