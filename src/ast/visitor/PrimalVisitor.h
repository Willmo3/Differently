//
// Created by will on 9/8/25.
//

#ifndef DIFFERENTLY_PRIMALVISITOR_H
#define DIFFERENTLY_PRIMALVISITOR_H
#include "AstVisitor.h"


class PrimalVisitor final : public AstVisitor {
    public:
    /*
     * Constructors
     */
    PrimalVisitor();
    ~PrimalVisitor() override;

    /*
     * Traversers
     */
    void visit(AstNode *node) override;
    void visit(BinaryOpNode *node) override;
    void visit(UnaryOpNode *node) override;
};


#endif //DIFFERENTLY_PRIMALVISITOR_H