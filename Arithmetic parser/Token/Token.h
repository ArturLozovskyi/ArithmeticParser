#pragma once

#include <iostream>
#include <map>

enum TokenType {
    PLUS='+',
    MINUS='-',
    MULTIPLY='*',
    DEVIDE='/',
    RIGHT_BRACKET=')',
    LEFT_BRACKET='(',
    NUMBER
};

const std::map<TokenType, std::string> tokenTypeName {
    { PLUS, "PLUS" },
    { MINUS, "MINUS" },
    { MULTIPLY, "MULTIPLY" },
    { DEVIDE, "DEVIDE" },
    { RIGHT_BRACKET, "RIGHT_BRACKET" },
    { LEFT_BRACKET, "LEFT_BRACKET" },
    { NUMBER, "NUMBER" }
};

class Token {
public:
    Token(TokenType type, size_t startPosition, size_t finishPosition);
    TokenType getType();
    size_t m_startPosition;
    size_t m_finishPositoon;
    virtual std::string toString();
    virtual ~Token();
protected:
    TokenType tokenType;
};
