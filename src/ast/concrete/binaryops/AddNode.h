//
// Created by will on 8/29/25.
//

#ifndef DIFFERENTLY_ADDNODE_H
#define DIFFERENTLY_ADDNODE_H
#include "../../abstract/BinaryOpNode.h"

class AddNode: public BinaryOpNode {
public:
    AddNode(AstNode *left, AstNode *right);
    ~AddNode() override;

    void accept(const AstVisitor *visitor) override;
};


#endif //DIFFERENTLY_ADDNODE_H