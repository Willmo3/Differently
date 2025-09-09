#ifndef DIFFERENTLY_POSTORDERVISITOR_H
#define DIFFERENTLY_POSTORDERVISITOR_H
#include "AstVisitor.h"

class TangentVisitor final : public AstVisitor {
    public:
        /*
         * Constructors
         */
        TangentVisitor();
        ~TangentVisitor() override;

        /*
         * Traversers
         */
        void visit(AstNode *node) override;
        void visit(BinaryOpNode *node) override;
        void visit(UnaryOpNode * node) override;
};


#endif //DIFFERENTLY_POSTORDERVISITOR_H