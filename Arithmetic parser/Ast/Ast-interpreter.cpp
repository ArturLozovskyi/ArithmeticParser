#include "Ast-interpreter.h"
#include "Algorithms.h"
#include "ValueToken.h"

void AstInterpreter::print(std::shared_ptr<AstNode> ast) {
    algorithms::inOrderTreeTraversal(ast, [](std::shared_ptr<AstNode> node) {
        std::cout << node->getToken()->toString() << "\n";
    });
}

double AstInterpreter::execute(std::shared_ptr<AstNode> ast) {
    switch (ast->getToken()->getType()) {
        case NUMBER:
            return std::dynamic_pointer_cast<ValueToken>(ast->getToken())->value;
        case PLUS:
            return execute(ast->getLeft()) + execute(ast->getRight());
        case MINUS:
            return execute(ast->getLeft()) - execute(ast->getRight());
        case MULTIPLY:
            return execute(ast->getLeft()) * execute(ast->getRight());
        case DEVIDE:
            return execute(ast->getLeft()) / execute(ast->getRight());
        default:
            break;
    }
    return 0;
}
