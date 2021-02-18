#pragma once

#include <vector>
#include <memory>

#include "Ast-node.h"
#include "Token.h"

class SyntaxParser {
public:
    SyntaxParser(std::vector<std::shared_ptr<Token>>);
    std::shared_ptr<AstNode> add();
    std::shared_ptr<AstNode> mul();
    std::shared_ptr<AstNode> number();
    std::shared_ptr<AstNode> execute();
private:
    bool match(std::initializer_list<TokenType>);
    std::vector<std::shared_ptr<Token>> m_tokens;
    size_t m_currentIndex = 0;
};

