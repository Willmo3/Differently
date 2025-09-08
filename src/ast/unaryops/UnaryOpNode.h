#ifndef DIFFERENTLY_UNARYNODE_H
#define DIFFERENTLY_UNARYNODE_H
#include "../AstNode.h"

class UnaryOpNode: public AstNode {
    public:
        enum UnaryOpType {
            EXP = 0,
        };

        /*
         * Constructors
         */
        explicit UnaryOpNode(AstNode *child);
        ~UnaryOpNode() override;

        /*
         * Accessors
         */
        virtual UnaryOpType optype() = 0;

        /*
         * Evaluators
         */
        void accept(AstVisitor* visitor) override;
    private:
        AstNode *child;

    // Select visitors allowed private access to fields.
    friend class PostorderVisitor;
};

#endif //DIFFERENTLY_UNARYNODE_H