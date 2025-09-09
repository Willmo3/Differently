#ifndef DIFFERENTLY_NUMBERNODE_H
#define DIFFERENTLY_NUMBERNODE_H
#include "AtomNode.h"


class ConstantNode final : public AtomNode {
public:
    /*
     * Constructors
     */
    explicit ConstantNode(double value);
    ~ConstantNode() override;
};


#endif //DIFFERENTLY_NUMBERNODE_H