#include "Variable.h"
#include "UserHandler.h"

Variable::Variable(std::string variableName, double value) : 
    variableName(variableName), valueSet(true), Value(value)
    {}

Variable::Variable(std::string variableName) : 
    variableName(variableName), Value(0), valueSet(false)
    {}

double Variable::calc() {
    if(valueSet){
        return value;
    }
    else{
        value = UserHandler::getVariableValueFromUser(variableName);
        valueSet = true;
        return value;
    }
}

std::string Variable::print() {
    if(valueSet){
        return  std::to_string(value);
    }
    else{
        return variableName;   
    }
}

