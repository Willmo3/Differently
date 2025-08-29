#ifndef DIFFERENTLY_AST_H
#define DIFFERENTLY_AST_H

// Forward definition to pass typechecking.
class AstVisitor;

class AstNode {
public:
    virtual ~AstNode() = default;

    virtual double primal_value() = 0;
    virtual double tangent_value() = 0;

    virtual void accept(const AstVisitor *visitor) = 0;
};

#endif //DIFFERENTLY_AST_H