#include "Parser.h"


Parser::Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.getStartToken()){}
Parser::Parser(const std::string& input) : lexer(*new Lexer(input)), currentToken(lexer.getStartToken()){}

//
void Parser::setNewInput(const std::string& input){
    lexer.setNewInput(input);
    currentToken = lexer.getNextToken();
}


INode* Parser::parseFactor(){
    INode* node;

    if (currentToken == Token::VALUE) {
        //double value = lexer.getCurrentValue();
        node = new Value(lexer.getCurrentValueSubstring()); 
        currentToken = lexer.getNextToken();
    }
    else if (currentToken == Token::VARIABLE){
        std::string variableName = lexer.getCurrentVariableName();
        node = new Variable(variableName);
        currentToken = lexer.getNextToken();
    }
    else if (currentToken == Token::LPARENS) {
        currentToken = lexer.getNextToken();
        node = parseExpression();
        if (currentToken != Token::RPARENS) {
            throw std::exception("Expected closing parenthesis");
        }
        currentToken = lexer.getNextToken();
    }
    else {
        throw std::exception("Expected number or opening parenthesis");
    }
    
    return node;
}

INode* Parser::parseTerm(){
    INode* node = parseFactor();
    while (currentToken == Token::MULTIPLY || currentToken == Token::DIVIDE ||
        currentToken == Token::LPARENS || currentToken == Token::VARIABLE)
    {
        Token op = currentToken;
        if(op == Token::LPARENS || op == Token::VARIABLE){
            node = new Multiplication(node,parseFactor());
        }
        else if(op == Token::MULTIPLY){
            currentToken = lexer.getNextToken();
            node = new Multiplication(node,parseFactor());
        }           
        else if(op == Token::DIVIDE){
            currentToken = lexer.getNextToken();
            node = new Division(node, parseFactor());
        }

    }
    return node;
}

INode* Parser::parseExpression(){
    INode* node = parseTerm();
    while (currentToken == Token::PLUS || currentToken == Token::MINUS) {
        Token op = currentToken;
        currentToken = lexer.getNextToken();
        if(op == Token::PLUS){
            node = new Sum(node,parseTerm());
        }
        else if(op == Token::MINUS){
            node = new Subtraction(node, parseTerm());
        }
    }
    return node;
}