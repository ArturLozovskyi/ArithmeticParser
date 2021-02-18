#pragma once

#include "Token.h"

class ValueToken: public Token {
public:
    ValueToken(TokenType type, double value, size_t startPosition, size_t finishPosition);
    std::string toString() override;
    double value;
    virtual ~ValueToken();
};
