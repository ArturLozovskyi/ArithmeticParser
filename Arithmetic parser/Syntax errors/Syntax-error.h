#pragma once

#include <string>

class SyntaxError: public std::exception {
    
public:
    explicit SyntaxError(const std::string &errorMessage);
    explicit SyntaxError(const std::string &errorMessage, size_t symbolNumber);
    
    virtual const char* what() const throw ();
    
    virtual ~SyntaxError();
    
private:
    std::string m_errorMessage;
    size_t m_symbolNumber;
    bool m_containErrorPosition;
};
