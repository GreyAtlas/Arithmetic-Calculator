#ifndef PARSER_H_
#define PARSER_H_

#include <exception>
#include "Lexer.h"
#include "Token.h"
#include "INode.h"
#include "Value.h"
#include "Variable.h"
#include "Sum.h"
#include "Subtraction.h"
#include "Division.h"
#include "Multiplication.h"

class Parser {
    Lexer& lexer; 
    Token currentToken;

    INode* parseFactor();
    INode* parseTerm();
    public: 
        Parser(Lexer& lexer);
        Parser(const std::string& input);
        void setNewInput(const std::string& input);
        INode* parseExpression();
};

#endif