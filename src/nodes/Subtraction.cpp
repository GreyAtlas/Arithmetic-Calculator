#include "Subtraction.h"

Subtraction::Subtraction(INode* l = nullptr, INode* r = nullptr): 
    left(l), right(r)
    {}

double Subtraction::calc() {
    return left->calc() - right->calc();
}

std::string Subtraction::print() {
    return "(" + left->print() + " - " + right->print() + ")";
}
