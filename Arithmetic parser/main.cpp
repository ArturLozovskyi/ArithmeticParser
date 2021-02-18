#include <iostream>
 
#include "Lexical-parser.h"
#include "Syntax-parser.h"
#include "Ast-interpreter.h"

int main(int argc, const char * argv[])
{
    auto lexicalParser = LexicalParser("8-1*2+10/2+1");
    
    try {
        auto tokens = lexicalParser.parse();
        std::cout << tokens.size() << '\n';
//        lexicalParser.print();
        
        auto syntaxParser = SyntaxParser(tokens);
        
        auto ast = syntaxParser.execute();
        
        AstInterpreter astInterpreter;
        
        astInterpreter.print(ast);
        
        std::cout << astInterpreter.execute(ast) << "\n";
        
    } catch (std::exception &err) {
        std::cout << err.what() << "\n";
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
