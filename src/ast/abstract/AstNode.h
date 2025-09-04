#ifndef DIFFERENTLY_AST_H
#define DIFFERENTLY_AST_H
#include <cstdint>

// Forward definition to pass typechecking.
class AstVisitor;

class AstNode {
public:
    virtual ~AstNode() = default;

    /**
     * @brief Current computed value of AST rooted here.
     * Will be changed after visitor pass.
     * @return The value of the ast
     */
    virtual double primal_value() = 0;

    /**
     * @brief Partial derivative of subtree wrt some variable.
     * @param variable_label Index of variable getting partial derivative
     * @return the value of the partial derivative wrt this variable
     */
    virtual double partial_derivative(uint32_t variable_label) = 0;

    /**
     * @brief Function to perform when visited.
     */
    virtual void evaluate() = 0;
};

#endif //DIFFERENTLY_AST_H