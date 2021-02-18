#pragma once

#include <string>
#include <memory>

#include "BaseTokenParser.h"
#include "Token.h"



class NumberTokenParser: public BaseTokenParser {
public:
    NumberTokenParser();
    bool parse(const std::string &inputString, size_t startIndex, size_t &finishIndex, std::shared_ptr<Token> &token) override;
private:
    bool charIsPoint(const char &c);
    void validateHasPoint(const char &c, bool &hasPoint, size_t errorPosition);
    bool charInGrammar(const char &c);
    void validateResult(const std::string &resultString, size_t errorPosition);
};
