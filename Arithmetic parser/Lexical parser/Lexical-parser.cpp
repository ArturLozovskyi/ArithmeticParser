#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Lexical-parser.h"
#include "NumberTokenParser.h"
#include "OperatorsTokenParser.h"
#include "Syntax-error.h"


LexicalParser::LexicalParser (const std::string& str): inputString(str) {}

std::vector<std::shared_ptr<Token>> LexicalParser::parse() {
    while (true) {
        bool isParsed = false;
        currentSymbol = inputString[currentIndex];
        
        if (isblank(currentSymbol)) {
            currentIndex++;
            continue;
        }
        
        for (auto &tokenParser: tokenParsers) {
            std::shared_ptr<Token> token;
            if (tokenParser->parse(inputString, currentIndex, currentIndex, token)) {
                isParsed = true;
                tokens.push_back(token);
                break;
            }
        }
        
        if (!isParsed) {
            throw SyntaxError("Unexpected sympol", currentIndex);
        }
        
        if (currentIndex == inputString.length() - 1) {
            break;
        }
        
        currentIndex++;
    }
    
    return tokens;
}

void LexicalParser::print () {
    for (auto &token: tokens) {
        std::cout << token->toString() << "\n";
    }
}

