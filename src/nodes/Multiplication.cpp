#include "Multiplication.h"

Multiplication::Multiplication(INode* l = nullptr, INode* r = nullptr): 
    left(l), right(r)
    {}

double Multiplication::calc() {
    return left->calc() * right->calc();
}

std::string Multiplication::print() {
    return "(" + left->print() + " * " + right->print() + ")";
}
