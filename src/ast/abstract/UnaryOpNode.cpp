#include "UnaryOpNode.h"

UnaryOpNode::UnaryOpNode(AstNode *child): _child(child) {}
UnaryOpNode::~UnaryOpNode() = default;

AstNode *UnaryOpNode::child() const { return _child; }
