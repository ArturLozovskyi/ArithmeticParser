#include "Syntax-parser.h"
#include "Syntax-error.h"

SyntaxParser::SyntaxParser (std::vector<std::shared_ptr<Token>> tokens): m_tokens(tokens) {}

bool SyntaxParser::match(std::initializer_list<TokenType> allowedTokens) {
    for (const auto& allowedToken: allowedTokens) {
        if (m_tokens[m_currentIndex]->getType() == allowedToken) {
            return true;
        }
    }
    return false;
}

std::shared_ptr<AstNode> SyntaxParser::execute() {
    return add();
}

std::shared_ptr<AstNode> SyntaxParser::add() {
    
    std::shared_ptr<AstNode> result = mul();
    
    while (match({PLUS, MINUS})) {
        std::shared_ptr<Token> operatorToken = m_tokens[m_currentIndex++];
        std::shared_ptr<AstNode> temp = mul();
        
        result = std::make_shared<AstNode>(operatorToken, result, temp);
    }
    
    return result;
}

std::shared_ptr<AstNode> SyntaxParser::mul() {
    
    std::shared_ptr<AstNode> result = number();
    
    while (match({MULTIPLY, DEVIDE})) {
        std::shared_ptr<Token> operatorToken = m_tokens[m_currentIndex++];
        std::shared_ptr<AstNode> temp = number();
        
        result = std::make_shared<AstNode>(operatorToken, result, temp);
    }
    
    return result;
}

std::shared_ptr<AstNode> SyntaxParser::number() {
    
    if (m_currentIndex >= m_tokens.size()) {
        throw SyntaxError("Unfinished expression");
    }
    
    if (m_tokens[m_currentIndex]->getType() != NUMBER) {
        throw SyntaxError("Unexpected token", m_tokens[m_currentIndex]->m_startPosition);
    }
    return std::make_shared<AstNode>(m_tokens[m_currentIndex++]);
}
