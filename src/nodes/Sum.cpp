#include "Sum.h"

Sum::Sum(INode* l = nullptr, INode* r = nullptr): 
    left(l), right(r)
    {}

double Sum::calc() {
    return left->calc() + right->calc();
}

std::string Sum::print() {
    return "(" + left->print() + " + " + right->print() + ")";
}
