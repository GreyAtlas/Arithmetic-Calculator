#ifndef DIVISION_H_
#define DIVISION_H_

#include "INode.h"
#include "Constants.h"
#include <exception>
class Division : public INode{
    INode* left;
    INode* right;

    public: 
        Division (INode* l, INode* r);
        virtual double calc();
        virtual std::string print();    
};

#endif