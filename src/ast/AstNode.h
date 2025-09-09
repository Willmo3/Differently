#ifndef DIFFERENTLY_AST_H
#define DIFFERENTLY_AST_H
#include <cstdint>

// Forward definition to pass typechecking.
class AstVisitor;

class AstNode {
public:
    AstNode();
    virtual ~AstNode();

    /**
     * @brief Current computed value of AST rooted here.
     * Will be changed after visitor pass.
     * @return The value of the ast
     */
    double numeric_value();

    /**
     * @brief Primal value of the terms related to some var in the subtree.
     * @param variable_label Index of variable getting partial derivative.
     * @return The primal value of the expression wrt some variable.
     */
    double partial_primal_value(uint32_t variable_label);
    /**
     * @brief Partial derivative of subtree wrt some variable.
     * @param variable_label Index of variable getting partial derivative
     * @return the value of the partial derivative wrt this variable
     */
    double partial_derivative(uint32_t variable_label);

    /**
     * @brief Function to perform when visited.
     */
    virtual void accept(AstVisitor *visitor) = 0;

protected:
    /**
     * Total numeric value of a tree.
     */
    double _numeric_value;
    /**
     * Primal values of all variables considered in the subtree.
     */
    double _primal_values[3];
    /**
     * Partial derivatives of all variables considered in the subtree.
     */
    // Note: a sum field is not needed, as all constants will be removed from derivative.
    double _partial_derivatives[3];
};

#endif //DIFFERENTLY_AST_H