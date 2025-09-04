//
// Created by will on 9/4/25.
//

#ifndef DIFFERENTLY_DIVNODE_H
#define DIFFERENTLY_DIVNODE_H
#include "../../abstract/BinaryOpNode.h"

class DivNode final : public BinaryOpNode {
public:
    /*
     * Constructors
     */
    DivNode(AstNode *left, AstNode *right);
    ~DivNode() override;

    BinaryOpType optype() override;
};

#endif //DIFFERENTLY_DIVNODE_H