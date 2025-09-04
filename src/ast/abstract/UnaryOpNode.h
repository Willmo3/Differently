#ifndef DIFFERENTLY_UNARYNODE_H
#define DIFFERENTLY_UNARYNODE_H
#include "AstNode.h"

class UnaryOpNode: public AstNode {
    public:
        explicit UnaryOpNode(AstNode *child);
        ~UnaryOpNode() override;

        void accept(AstVisitor* visitor) override;
    private:
        AstNode *child;

    // Select visitors allowed private access to fields.
    friend class PostorderVisitor;
};

#endif //DIFFERENTLY_UNARYNODE_H