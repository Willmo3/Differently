//
// Created by will on 9/3/25.
//

#ifndef DIFFERENTLY_MULTNODE_H
#define DIFFERENTLY_MULTNODE_H
#include "../../abstract/BinaryOpNode.h"

class MultNode final : public BinaryOpNode {
public:
    /*
     * Constructors
     */
    MultNode(AstNode *left, AstNode *right);
    ~MultNode() override;

    BinaryOpType optype() override;
};

#endif //DIFFERENTLY_MULTNODE_H