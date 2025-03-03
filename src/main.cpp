#include <iostream>
#include <exception>
#include "Sum.h"
#include "INode.h"
#include "Value.h"
#include "Lexer.h"
#include "Parser.h"
#include "Token.h"


int main(int argc, char** argv){
    if(argc < 2){
        std::cout<< "Usage: executable \"expression\"";
        return 0;
    }

    INode* root = nullptr;
    try {
        Parser parser = Parser( argv[1]);
        root = parser.parseExpression();
        std::cout << "Result: " << root->calc() << std::endl;
        std::cout << "Order of operations : " << root->print() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
