#include <iostream>
#include <memory>


#include "NumberTokenParser.h"
#include "ValueToken.h"
#include "Syntax-error.h"
#include <stdlib.h>

NumberTokenParser::NumberTokenParser () {}

bool NumberTokenParser::parse(const std::string &inputString, size_t startIndex, size_t &finishIndex, std::shared_ptr<Token> &token) {
    
    if (!charInGrammar(inputString[startIndex])) {
        return false;
    }
    
    bool hasPoint = false;
    size_t i = startIndex;
    std::string result;
    
    while (true) {
        char currentChar = inputString[i];
        validateHasPoint(currentChar, hasPoint, i);
        if (charInGrammar(currentChar)) {
            result.push_back(currentChar);
            i++;
        } else {
            validateResult(result, startIndex);
            finishIndex = i - 1;
            token = std::shared_ptr<Token>(new ValueToken(NUMBER, atof(result.c_str()), startIndex, finishIndex));
            return true;
        }
    }
}

bool NumberTokenParser::charInGrammar(const char &c) {
    return (isdigit(c) || charIsPoint(c));
}

bool NumberTokenParser::charIsPoint(const char &c) {
    return (c == '.');
}

void NumberTokenParser::validateHasPoint(const char &c, bool &hasPoint, size_t errorPosition) {
    if (charIsPoint(c)) {
        if (hasPoint) {
            throw SyntaxError("Number can contain only one \".\"", errorPosition);
        }
        hasPoint = true;
    }
}

void NumberTokenParser::validateResult(const std::string &resultString, size_t errorPosition) {
    if (resultString.length() == 1 && charIsPoint(resultString[0])) {
        throw SyntaxError("Number can't contain only \".\"", errorPosition);
    }
}

