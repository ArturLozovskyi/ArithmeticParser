#pragma once

#include <string>
#include <vector>
#include <memory>
#include "BaseTokenParser.h"
#include "NumberTokenParser.h"
#include "OperatorsTokenParser.h"
#include "Token.h"

class LexicalParser {
public:
    LexicalParser (const std::string& str);
    std::vector<std::shared_ptr<Token>> parse();
    void print();
    
private:
    const std::string inputString;
    std::vector<std::shared_ptr<BaseTokenParser>> tokenParsers {
        std::shared_ptr<BaseTokenParser>(new NumberTokenParser()),
        std::shared_ptr<BaseTokenParser>(new OperatorsTokenParser()),
    };
    std::vector<std::shared_ptr<Token>> tokens;
    char currentSymbol = 0;
    size_t currentIndex = 0;
};
