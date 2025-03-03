#include "Lexer.h"


Lexer::Lexer(const std::string& input) : input(input), pos(0){} 
void Lexer::skipWhitespace(){
    while (pos < input.size() && isspace(input[pos])) {
        pos++;
    }
}

void Lexer::setNewInput(const std::string& i){
    input.assign(i);
    pos = 0;
}


Token Lexer::getNextToken() {
    skipWhitespace();
        
    if (pos >= input.size()) return Token::END;

    if (isdigit(input[pos])) {
        return Token::VALUE;
    }
    if(isalpha(input[pos])){
        return Token::VARIABLE;
    }
    if (input[pos] == '+') {
        pos++;
        return Token::PLUS;
    }
    if (input[pos] == '-') {
        pos++;
        return Token::MINUS;
    }
    if (input[pos] == '*') {
        pos++;
        return Token::MULTIPLY;
    }
    if (input[pos] == '/') {
        pos++;
        return Token::DIVIDE;
    }
    if (input[pos] == '(') {
        pos++;
        return Token::LPARENS;
    }
    if (input[pos] == ')') {
        pos++;
        return Token::RPARENS;
    }

    return Token::INVALID;
}

Token Lexer::getStartToken(){
    pos = 0;
    return this->getNextToken();
}

double Lexer::getCurrentValue() {
    size_t start = pos;
    while (pos < input.size() && (isdigit(input[pos]) ||input[pos] == '.')) {
        pos++;
    }
    return stod(input.substr(start, pos - start));
}


std::string Lexer::getCurrentValueSubstring() {
    size_t start = pos;
    while (pos < input.size() && (isdigit(input[pos]) ||input[pos] == '.')) {
        pos++;
    }
    return input.substr(start, pos - start);
}

std::string Lexer::getCurrentVariableName() {
    size_t start = pos;
    while (pos < input.size() && isalpha(input[pos])) {
        pos++;
    }
    return input.substr(start, pos - start);
}

