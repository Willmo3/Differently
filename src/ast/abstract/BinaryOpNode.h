#ifndef DIFFERENTLY_BINARYNODE_H
#define DIFFERENTLY_BINARYNODE_H
#include "AstNode.h"

class BinaryOpNode: public AstNode {
    public:
        BinaryOpNode(AstNode *left, AstNode *right);
        ~BinaryOpNode() override;

        void accept(const AstVisitor *visitor) override = 0;

        AstNode *left() const;
        AstNode *right() const;

    private:
        AstNode *left_;
        AstNode *right_;
};


#endif //DIFFERENTLY_BINARYNODE_H