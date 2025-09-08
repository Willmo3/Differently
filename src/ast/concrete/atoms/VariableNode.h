#ifndef DIFFERENTLY_VARIABLENODE_H
#define DIFFERENTLY_VARIABLENODE_H
#include "../../abstract/AtomNode.h"

class VariableNode final : public AtomNode {
public:
    /*
     * Constructors
     */
    VariableNode(double value, uint32_t label);
    ~VariableNode() override;

    /*
     * Accessors
     */
    double primal_value() override;
    double partial_derivative(uint32_t var_label) override;
private:
    uint32_t label;
};


#endif //DIFFERENTLY_VARIABLENODE_H