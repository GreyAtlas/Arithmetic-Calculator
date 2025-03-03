#include "UserHandler.h"

double UserHandler::getVariableValueFromUser(const std::string& variableName){
    std::cout << "Enter value for variable: "<< variableName << " = ";

    std::string input;
    std::getline(std::cin, input);
    
    return stod(input);

}
