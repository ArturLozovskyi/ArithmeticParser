
#include <iostream>

#include "Token.h"

Token::Token(TokenType type, size_t startPosition, size_t finishPosition) : tokenType(type), m_startPosition(startPosition), m_finishPositoon(finishPosition) {}

TokenType Token::getType() {
    return tokenType;
}

std::string Token::toString() {
    return tokenTypeName.at(tokenType);
}

Token::~Token() {}
