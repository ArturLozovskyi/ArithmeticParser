#pragma once

#include <memory>

#include "Token.h"

class AstNode {
public:
    AstNode(std::shared_ptr<Token>);
    AstNode(std::shared_ptr<Token>, std::shared_ptr<AstNode>);
    AstNode(std::shared_ptr<Token>, std::shared_ptr<AstNode>, std::shared_ptr<AstNode>);
    const std::shared_ptr<Token> getToken();
    const std::shared_ptr<AstNode> getRight();
    const std::shared_ptr<AstNode> getLeft();
    
    // preorderBegin -> specific iterator
    // postOrderBegin -> specific iterator
private:
    std::shared_ptr<Token> m_token;
    std::shared_ptr<AstNode> m_left;
    std::shared_ptr<AstNode> m_right;
};
