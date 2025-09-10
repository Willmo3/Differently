cmake_minimum_required(VERSION 4.0)
project(differently)

set(CMAKE_CXX_STANDARD 23)

add_executable(differently src/main.cpp
        src/ast/AstNode.h
        src/ast/binaryops/BinaryOpNode.h
        src/ast/unaryops/UnaryOpNode.h
        src/ast/atoms/ConstantNode.cpp
        src/ast/atoms/ConstantNode.h
        src/ast/visitor/AstVisitor.h
        src/ast/visitor/TangentVisitor.cpp
        src/ast/visitor/TangentVisitor.h
        src/ast/binaryops/BinaryOpNode.cpp
        src/ast/unaryops/UnaryOpNode.cpp
        src/ast/atoms/VariableNode.cpp
        src/ast/atoms/VariableNode.h
        src/ast/atoms/AtomNode.cpp
        src/ast/atoms/AtomNode.h
        src/ast/AstNode.cpp
        src/ast/visitor/NumericVisitor.cpp
        src/ast/visitor/NumericVisitor.h
        src/ast/unaryops/PowNode.cpp
        src/ast/unaryops/PowNode.h
        src/ast/visitor/PrimalVisitor.cpp
        src/ast/visitor/PrimalVisitor.h
)
