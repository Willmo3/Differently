//
// Created by will on 9/3/25.
//

#ifndef DIFFERENTLY_MULTNODE_H
#define DIFFERENTLY_MULTNODE_H
#include "../../abstract/BinaryOpNode.h"


class MultNode: public BinaryOpNode {
public:
    MultNode(AstNode *left, AstNode *right);
    ~MultNode() override;

    void accept(const AstVisitor *visitor) override;
    double primal_value() override;
    double tangent_value() override;

private:
    double _primal_value;
    double _tangent_value;
};


#endif //DIFFERENTLY_MULTNODE_H