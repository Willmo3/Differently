#ifndef DIFFERENTLY_UNARYNODE_H
#define DIFFERENTLY_UNARYNODE_H

#include "../AstNode.h"

class UnaryOpNode: public AstNode {
    public:
        enum UnaryOpType {
            POW = 0,
        };

        /*
         * Constructors
         */
        explicit UnaryOpNode(AstNode *child, UnaryOpType type);
        ~UnaryOpNode() override;

        /*
         * Accessors
         */
        UnaryOpType optype() const;

        /*
         * Evaluators
         */
        void accept(AstVisitor* visitor) override;
    private:
        AstNode *child;
        UnaryOpType _optype;

    // Select visitors allowed private access to fields.
    friend class NumericVisitor;
    friend class TangentVisitor;
};

#endif //DIFFERENTLY_UNARYNODE_H