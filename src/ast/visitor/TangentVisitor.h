#ifndef DIFFERENTLY_TANGENTVISITOR_H
#define DIFFERENTLY_TANGENTVISITOR_H
#include "AstVisitor.h"

class TangentVisitor final : public AstVisitor {
    public:
        /*
         * Constructors
         */
        TangentVisitor();
        ~TangentVisitor() override;

        /*
         * Visit functions
         */
        void visit(AstNode *node) override;
        void visit(BinaryOpNode *node) override;
        void visit(UnaryOpNode * node) override;
};

#endif //DIFFERENTLY_TANGENTVISITOR_H