#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "Value.h"
#include <string>

class Variable : public Value{
    bool valueSet;
    std::string variableName;

    public: 
        Variable(std::string variableName);
        Variable(std::string variableName, double value);
        virtual double calc();
        virtual std::string print();    
        void setVariableValue();
};

#endif