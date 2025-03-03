#ifndef MULTIPLICATION_H_
#define MULTIPLICATION_H_

#include "INode.h"

class Multiplication : public INode{
    INode* left;
    INode* right;

    public: 
        Multiplication(INode* l, INode* r);
        virtual double calc();
        virtual std::string print();    
};

#endif