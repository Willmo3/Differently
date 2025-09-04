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
        BinaryOpNode(AstNode *left, AstNode *right);
        ~BinaryOpNode() override;

        /*
         * Accessors
         */
        double primal_value() override;
        double partial_derivative(uint32_t variable_label) override;
        virtual BinaryOpType optype() = 0;

        /*
         * Evaluators
         */
        void accept(AstVisitor *visitor) override;

        /**
         * @brief Loop over all variables in this datum, computing their partial derivatives as specified by the subclass.
         * @param compute_pd_atom Function to compute a single partial derivative, given a variable.
         */
        void compute_partial_derivatives(const std::function<double(uint32_t)>& compute_pd_atom);

    protected:
        double _primal_value;
        double _partial_derivatives[3];

    private:
        AstNode *left;
        AstNode *right;

    // Visitors need access to fields for evaluation.
    friend class PostorderVisitor;
};


#endif //DIFFERENTLY_BINARYNODE_H