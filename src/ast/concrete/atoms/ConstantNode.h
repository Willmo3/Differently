#ifndef DIFFERENTLY_NUMBERNODE_H
#define DIFFERENTLY_NUMBERNODE_H
#include "../../abstract/AtomNode.h"


class ConstantNode final : public AtomNode {
public:
    explicit ConstantNode(double value);
    ~ConstantNode() override;

    double primal_value() override;
    double partial_derivative(uint32_t) override;
private:
    double _primal_value;
    double _tangent_value;
};


#endif //DIFFERENTLY_NUMBERNODE_H