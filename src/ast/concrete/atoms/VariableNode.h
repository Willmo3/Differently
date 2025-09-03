#ifndef DIFFERENTLY_VARIABLENODE_H
#define DIFFERENTLY_VARIABLENODE_H
#include "../../abstract/AtomNode.h"


class VariableNode: public AtomNode {
public:
    VariableNode(double value, uint32_t label);
    ~VariableNode() override;

    void accept(const AstVisitor *visitor) override;

    double primal_value() override;
    double partial_derivative(uint32_t var_label) override;

private:
    uint32_t label;
    double _primal_value;
    double _tangent_value;
};


#endif //DIFFERENTLY_VARIABLENODE_H