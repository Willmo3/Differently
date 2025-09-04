#ifndef DIFFERENTLY_ATOMNODE_H
#define DIFFERENTLY_ATOMNODE_H
#include "AstNode.h"

class AtomNode: public AstNode {
public:
    void evaluate() override = 0;
};


#endif //DIFFERENTLY_ATOMNODE_H