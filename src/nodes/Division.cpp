#include "Division.h"

Division::Division(INode* l = nullptr, INode* r = nullptr): 
    left(l), right(r)
    {}

double Division::calc() {
    double temp = right->calc();
    if(std::fabs(temp - 0.0) < mathConstants::DOUBLE_COMPARISON_PRECISION){
        throw std::exception("Division by zero");
    }
    return left->calc() / right->calc();
}

std::string Division::print() {
    double temp = right->calc();
    if(std::fabs(temp - 0.0) < mathConstants::DOUBLE_COMPARISON_PRECISION){
        return "(" + left->print() + " ! / " + right->print() + " ) ! ";
    }
    else{
        return "(" + left->print() + " / " + right->print() + ")";
    }

}
