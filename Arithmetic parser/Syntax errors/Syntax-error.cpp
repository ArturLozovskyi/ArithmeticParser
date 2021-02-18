
#include "Syntax-error.h"

SyntaxError::SyntaxError(const std::string &errorMessage): m_errorMessage(errorMessage), m_containErrorPosition(false) {}

SyntaxError::SyntaxError(const std::string &errorMessage, size_t symbolNumber): m_errorMessage(errorMessage), m_symbolNumber(symbolNumber), m_containErrorPosition(true) {}

const char* SyntaxError::what() const throw () {
    if (!m_containErrorPosition) {
        return m_errorMessage.c_str();
    }
    const std::string message = m_errorMessage + ". "  + "Error at " + std::to_string(m_symbolNumber) + " symbol.";
    return message.c_str();
}

SyntaxError::~SyntaxError() {}
