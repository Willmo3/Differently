#include "UnaryOpNode.h"

/*
 * Constructors
 */
UnaryOpNode::UnaryOpNode(AstNode *child): _child(child) {}
UnaryOpNode::~UnaryOpNode() = default;

/*
 * Accessors
 */
AstNode *UnaryOpNode::child() const { return _child; }
