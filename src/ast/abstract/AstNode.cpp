//
// Created by will on 9/8/25.
//

#include "AstNode.h"

#include <cstring>

/*
 * Constructors
 */
AstNode::AstNode() {
    _primal_value = 0;
    memset(&_partial_derivatives, 0, sizeof(_partial_derivatives));
}
AstNode::~AstNode() = default;