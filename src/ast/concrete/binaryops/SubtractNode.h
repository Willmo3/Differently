//
// Created by will on 9/8/25.
//

#ifndef DIFFERENTLY_SUBNODE_H
#define DIFFERENTLY_SUBNODE_H
#include "../../abstract/BinaryOpNode.h"


class SubtractNode final: public BinaryOpNode {
public:
    /*
     * Constructors
     */
    SubtractNode(AstNode *left, AstNode *right);
    ~SubtractNode() override;

    BinaryOpType optype() override;
};


#endif //DIFFERENTLY_SUBNODE_H