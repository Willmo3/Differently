cmake_minimum_required(VERSION 4.0)
project(differently)

set(CMAKE_CXX_STANDARD 23)

add_executable(differently main.cpp
        src/ast/abstract/AstNode.h
        src/ast/abstract/BinaryOpNode.h
        src/ast/abstract/UnaryOpNode.h
        src/ast/concrete/ConstantNode.cpp
        src/ast/concrete/ConstantNode.h
        src/ast/abstract/AtomNode.h
        src/ast/visitor/AstVisitor.h
        src/ast/visitor/PostorderVisitor.cpp
        src/ast/visitor/PostorderVisitor.h
        src/ast/abstract/BinaryOpNode.cpp
        src/ast/abstract/UnaryOpNode.cpp
        src/ast/concrete/VariableNode.cpp
        src/ast/concrete/VariableNode.h
)
