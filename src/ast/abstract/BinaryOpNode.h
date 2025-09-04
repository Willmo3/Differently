#ifndef DIFFERENTLY_BINARYNODE_H
#define DIFFERENTLY_BINARYNODE_H
#include <functional>

#include "AstNode.h"

class BinaryOpNode: public AstNode {
    public:
        BinaryOpNode(AstNode *left, AstNode *right);
        ~BinaryOpNode() override;

        double primal_value() override;
        double partial_derivative(uint32_t variable_label) override;

        void accept(const AstVisitor *visitor) override = 0;

        /**
         * @brief Loop over all variables in this datum, computing their partial derivatives as specified by the subclass.
         * @param compute_pd_atom Function to compute a single partial derivative, given a variable.
         */
        void compute_partial_derivatives(const std::function<double(uint32_t)>& compute_pd_atom);

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