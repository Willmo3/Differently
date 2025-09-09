//
// Created by will on 9/9/25.
//

#ifndef DIFFERENTLY_POWNODE_H
#define DIFFERENTLY_POWNODE_H
#include "UnaryOpNode.h"

class PowNode: public UnaryOpNode {
    public:
        /*
         * Constructors
         */
        PowNode(AstNode *child, double exp_factor);
        ~PowNode() override;

        /*
         * Accessors
         */
        double exp_factor() const;

    private:
        double _exp_factor;

};


#endif //DIFFERENTLY_POWNODE_H