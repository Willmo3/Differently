//
// Created by will on 9/9/25.
//

#ifndef DIFFERENTLY_PRIMALVISITOR_H
#define DIFFERENTLY_PRIMALVISITOR_H
#include "AstVisitor.h"

class PrimalVisitor final: public AstVisitor {
    public:
        /*
         * Constructors
         */
        PrimalVisitor();
        ~PrimalVisitor() override;

        /*
         * Visit functions
         */
        void visit(AstNode *node) override;
        void visit(BinaryOpNode *node) override;
        void visit(UnaryOpNode *node) override;
};

#endif //DIFFERENTLY_PRIMALVISITOR_H