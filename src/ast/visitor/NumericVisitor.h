//
// Created by will on 9/8/25.
//

#ifndef DIFFERENTLY_NUMERICVISITOR_H
#define DIFFERENTLY_NUMERICVISITOR_H
#include "AstVisitor.h"

class NumericVisitor final : public AstVisitor {
    public:
        /*
         * Constructors
         */
        NumericVisitor();
        ~NumericVisitor() override;

        /*
         * Visit functions
         */
        void visit(AstNode *node) override;
        void visit(BinaryOpNode *node) override;
        void visit(UnaryOpNode * node) override;
};


#endif //DIFFERENTLY_NUMERICVISITOR_H