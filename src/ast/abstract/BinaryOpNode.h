#ifndef DIFFERENTLY_BINARYNODE_H
#define DIFFERENTLY_BINARYNODE_H
#include <functional>

#include "AstNode.h"

class BinaryOpNode: public AstNode {
    public:
        enum BinaryOpType {
            ADD = 0,
            SUB,
            MULT,
            DIV,
        };

        /*
         * Constructors
         */
        BinaryOpNode(BinaryOpType type, AstNode *left, AstNode *right);
        ~BinaryOpNode() override;

        /*
         * Accessors
         */
        double primal_value() override;
        double partial_derivative(uint32_t variable_label) override;
        BinaryOpType optype() const;

        /*
         * Evaluators
         */
        void accept(AstVisitor *visitor) override;

    protected:
        double _primal_value;
        double _partial_derivatives[3];
        BinaryOpType _type;

    private:
        AstNode *left;
        AstNode *right;

    // Visitors need access to fields for evaluation.
    friend class PostorderVisitor;
};


#endif //DIFFERENTLY_BINARYNODE_H