#ifndef LEXER_H_
#define LEXER_H_

#include <string>
#include "Token.h"
#include <cctype>
#include <string>

class Lexer{
    std::string input;
    size_t pos;

    void skipWhitespace();

    public: 
        Lexer(const std::string& input);
        void setNewInput(const std::string& i);
        Token getNextToken();
        Token getStartToken();
        double getCurrentValue();
        std::string getCurrentValueSubstring();
        std::string getCurrentVariableName();
};

#endif