//
// Created by will on 9/4/25.
//

// TODO: again, think I can probably remove this.
#include "AtomNode.h"

#include "../visitor/AstVisitor.h"

AtomNode::AtomNode() = default;
AtomNode::~AtomNode() = default;

void AtomNode::accept(AstVisitor *visitor) {
    visitor->visit(this);
}

