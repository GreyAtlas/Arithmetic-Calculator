#ifndef VALUE_H_
#define VALUE_H_

#include "INode.h"
#include <sstream>
class Value : public INode{
    
    protected:
        double value;
        int sigDigits;
    public: 
        Value(double v);
        Value(double v, int sigDigits);
        Value(const std::string& valueString);
        virtual double calc();
        virtual std::string print(); 
};

#endif