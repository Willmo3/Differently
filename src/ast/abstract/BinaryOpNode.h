#ifndef DIFFERENTLY_BINARYNODE_H
#define DIFFERENTLY_BINARYNODE_H
#include "AstNode.h"

class BinaryOpNode: public AstNode {
    public:
        BinaryOpNode(AstNode *left, AstNode *right);
        ~BinaryOpNode() override;

        double primal_value() override;
        double partial_derivative(uint32_t variable_label) override;

        void accept(const AstVisitor *visitor) override = 0;
        AstNode *left() const;
        AstNode *right() const;

    protected:
        double _primal_value;
        double _partial_derivatives[3];

    private:
        AstNode *left_;
        AstNode *right_;
};


#endif //DIFFERENTLY_BINARYNODE_H