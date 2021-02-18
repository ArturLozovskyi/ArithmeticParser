#pragma once

#include <string>
#include <memory>

#include "Token.h"

#include "BaseTokenParser.h"

class OperatorsTokenParser: public BaseTokenParser {
public:
    OperatorsTokenParser();
    bool parse(const std::string &inputString, size_t startIndex, size_t &finishIndex, std::shared_ptr<Token> &token) override;
private:
    
};
