//
// Created by will on 9/4/25.
//

// TODO: again, think I can probably remove this.
#include "AtomNode.h"

#include "../visitor/AstVisitor.h"

/*
 * Constructors
 */
AtomNode::AtomNode() = default;
AtomNode::~AtomNode() = default;

/*
 * Traversers
 */
void AtomNode::accept(AstVisitor *visitor) {
    visitor->visit(this);
}