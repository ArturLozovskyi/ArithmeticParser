#pragma once

#include <memory>
#include "Ast-node.h"

namespace algorithms {

template <typename Func>
void inOrderTreeTraversal (std::shared_ptr<AstNode> ast, Func f) {
    if (ast == nullptr) {
        return;
    }
    
    inOrderTreeTraversal(ast->getRight(), f);
    
    f(ast);
    
    inOrderTreeTraversal(ast->getLeft(), f);
}

}
// Шаблонный класс алгоритмов шаблонный
// Base iterator interface, 3 iterators. std::list(iterator) see methods
// strategy
