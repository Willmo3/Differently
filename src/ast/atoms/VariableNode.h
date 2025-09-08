#ifndef DIFFERENTLY_VARIABLENODE_H
#define DIFFERENTLY_VARIABLENODE_H
#include "AtomNode.h"

class VariableNode final : public AtomNode {
public:
    /*
     * Constructors
     */
    VariableNode(double value, uint32_t label);
    ~VariableNode() override;
private:
    uint32_t label;
};

#endif //DIFFERENTLY_VARIABLENODE_H