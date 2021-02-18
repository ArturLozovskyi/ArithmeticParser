#pragma once

#include <memory>
#include "Ast-node.h"

class AstInterpreter {
public:
    void print(std::shared_ptr<AstNode>);
    double execute(std::shared_ptr<AstNode>);
};
