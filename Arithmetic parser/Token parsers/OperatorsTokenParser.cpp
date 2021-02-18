
#include <iostream>

#include "OperatorsTokenParser.h"
#include "Token.h"

OperatorsTokenParser::OperatorsTokenParser () {}

bool OperatorsTokenParser::parse(const std::string &inputString, size_t startIndex, size_t &finishIndex, std::shared_ptr<Token> &token) {
    const char currentChar = inputString[startIndex];
    switch (currentChar) {
        case PLUS: {
            token = std::shared_ptr<Token>(new Token(PLUS, startIndex, startIndex + 1));
            return true;
        }
        
        case MINUS: {
            token = std::shared_ptr<Token>(new Token(MINUS, startIndex, startIndex + 1));
            return true;
        }
            
        case MULTIPLY: {
            token = std::shared_ptr<Token>(new Token(MULTIPLY, startIndex, startIndex + 1));
            return true;
        }
            
        case DEVIDE: {
            token = std::shared_ptr<Token>(new Token(DEVIDE, startIndex, startIndex + 1));
            return true;
        }
            
        default: {
            return false;
        }
    }
}
