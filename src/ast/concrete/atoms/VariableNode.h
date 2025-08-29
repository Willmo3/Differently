#ifndef DIFFERENTLY_VARIABLENODE_H
#define DIFFERENTLY_VARIABLENODE_H
#include "../../abstract/AtomNode.h"


class VariableNode: public AtomNode {
public:
    explicit VariableNode(double value);
    ~VariableNode() override;

    void accept(const AstVisitor *visitor) override;

    double primal_value() override;
    double tangent_value() override;

private:
    double _primal_value;
    double _tangent_value;
};


#endif //DIFFERENTLY_VARIABLENODE_H