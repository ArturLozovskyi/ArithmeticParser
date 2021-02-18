
#include "ValueToken.h"

ValueToken::ValueToken(TokenType type, double value, size_t startPosition, size_t finishPosition): Token(type, startPosition, finishPosition), value(value) {}

std::string ValueToken::toString() {
    return tokenTypeName.at(tokenType) + " " + std::to_string(value);
}

ValueToken::~ValueToken() {}
