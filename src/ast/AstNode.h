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
    double primal_value();
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
    double _primal_value;
    double _partial_derivatives[3];
};

#endif //DIFFERENTLY_AST_H