//
// Created by will on 9/4/25.
//

#ifndef DIFFERENTLY_ATOMNODE_H
#define DIFFERENTLY_ATOMNODE_H
#include "AstNode.h"


class AtomNode: public AstNode {
public:
    AtomNode();
    ~AtomNode() override;

    void accept(AstVisitor* visitor) override;
};


#endif //DIFFERENTLY_ATOMNODE_H