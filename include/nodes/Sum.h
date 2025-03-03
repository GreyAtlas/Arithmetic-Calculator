#ifndef SUM_H_
#define SUM_H_

#include "INode.h"
class Sum : public INode{
    INode* left;
    INode* right;

    public: 
        Sum(INode* l, INode* r);
        virtual double calc();
        virtual std::string print();    
};

#endif