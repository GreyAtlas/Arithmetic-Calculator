#ifndef SUBTRACTION_H_
#define SUBTRACTION_H_

#include "INode.h"

class Subtraction : public INode{
    INode* left;
    INode* right;

    public: 
        Subtraction(INode* l, INode* r);
        virtual double calc();
        virtual std::string print();    
};

#endif