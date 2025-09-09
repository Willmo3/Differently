#ifndef DIFFERENTLY_BINARYNODE_H
#define DIFFERENTLY_BINARYNODE_H

#include "../AstNode.h"

class BinaryOpNode: public AstNode {
    public:
        /**
         * Set of supported binary operations
         * TODO: remove exp as binop -- adding single base, in compliance with past ScalarFlow work.
         */
        enum BinaryOpType {
            ADD = 0,
            SUB,
            MULT,
            DIV,
            EXP,
        };

        /*
         * Constructors
         */
        BinaryOpNode(BinaryOpType type, AstNode *left, AstNode *right);
        ~BinaryOpNode() override;
        /*
         * Accessors
         */
        BinaryOpType optype() const;
        /*
         * Evaluators
         */
        void accept(AstVisitor *visitor) override;

    protected:
        BinaryOpType _type;

    private:
        AstNode *left;
        AstNode *right;

    // Visitors need access to fields for evaluation.
    friend class NumericVisitor;
    friend class PrimalVisitor;
    friend class TangentVisitor;
};


#endif //DIFFERENTLY_BINARYNODE_H