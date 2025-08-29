#ifndef DIFFERENTLY_NUMBERNODE_H
#define DIFFERENTLY_NUMBERNODE_H
#include "../../abstract/AtomNode.h"

class ConstantNode final : public AstNode {
public:
    explicit ConstantNode(double value);
    void accept(const AstVisitor *visitor) override;

    double primal_value() override;
    double tangent_value() override;
private:
    double _primal_value;
    double _tangent_value;
};


#endif //DIFFERENTLY_NUMBERNODE_H