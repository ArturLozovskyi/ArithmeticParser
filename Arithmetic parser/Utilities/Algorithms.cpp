#include "Algorithms.h"

template <typename Func>
void algorithms::inOrderTreeTraversal (std::shared_ptr<AstNode> ast, Func f) {
    if (ast == nullptr) {
        return;
    }
    
    inOrderTreeTraversal(ast->getRight(), f);
    
    f(ast);
    
    inOrderTreeTraversal(ast->getLeft(), f);
}
