#ifndef DIFFERENTLY_ASTVISITOR_H
#define DIFFERENTLY_ASTVISITOR_H
#include "../abstract/BinaryOpNode.h"

class UnaryOpNode;

class AstVisitor {
    public:
    virtual ~AstVisitor() = default;

    virtual void visit(AstNode *node) = 0;
    virtual void visit(BinaryOpNode *node) = 0;
    virtual void visit(UnaryOpNode *node) = 0;
};


#endif //DIFFERENTLY_ASTVISITOR_H