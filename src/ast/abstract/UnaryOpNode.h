#ifndef DIFFERENTLY_UNARYNODE_H
#define DIFFERENTLY_UNARYNODE_H
#include "AstNode.h"

class UnaryOpNode: public AstNode {
    public:
        explicit UnaryOpNode(AstNode *child);
        ~UnaryOpNode() override;

        void evaluate() override = 0;
        AstNode *child() const;
    private:
        AstNode *_child;
};

#endif //DIFFERENTLY_UNARYNODE_H